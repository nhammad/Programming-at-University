import numpy as np
from sklearn.feature_extraction.image import extract_patches_2d

# Reference: https://www.youtube.com/watch?v=YgtModJ-4cw

def conv_nested(image, kernel):
    """A naive implementation of convolution filter.

    This is a naive implementation of convolution using 4 nested for-loops.
    This function computes convolution of an image with a kernel and outputs
    the result that has the same shape as the input image.

    Args:
        image: numpy array of shape (Hi, Wi).
        kernel: numpy array of shape (Hk, Wk).

    Returns:
        out: numpy array of shape (Hi, Wi).
    """
    Hi, Wi = image.shape
    Hk, Wk = kernel.shape
    out = np.zeros((Hi, Wi))

    ### YOUR CODE HERE
    for x in range(Hi):
        for y in range(Wi):
            val = 0
            for i in range(Hk):
                for j in range(Wk):
                    # boundaries 
                    if x + 1 - i < 0 or y + 1 - j < 0 or x + 1 - i >= Hi or y + 1-j >= Wi:
                        val += 0
                    else:
                        # multiplying value from image with a value from kernel 
                        # and then adding all such values
                        val += kernel[i][j] * image[x + 1 - i][y + 1 - j]
            out[x][y] = val
    ### END YOUR CODE

    return out

# Reference: https://stackoverflow.com/questions/35751306/python-how-to-pad-numpy-array-with-zeros

def zero_pad(image, pad_height, pad_width):
    """ Zero-pad an image.

    Ex: a 1x1 image [[1]] with pad_height = 1, pad_width = 2 becomes:

        [[0, 0, 0, 0, 0],
         [0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0]]         of shape (3, 5)

    Args:
        image: numpy array of shape (H, W).
        pad_width: width of the zero padding (left and right padding).
        pad_height: height of the zero padding (bottom and top padding).

    Returns:
        out: numpy array of shape (H+2*pad_height, W+2*pad_width).
    """

    ### YOUR CODE HERE
    H, W = image.shape
    out = np.zeros((H + 2 * pad_height, W + 2 * pad_width))
    out[pad_height: pad_height + H, pad_width: pad_width + W] = image
    ### END YOUR CODE
    return out

# Reference: https://www.geeksforgeeks.org/numpy-flip-python/

def conv_fast(image, kernel):
    """ An efficient implementation of convolution filter.

    This function uses element-wise multiplication and np.sum()
    to efficiently compute weighted sum of neighborhood at each
    pixel.

    Hints:
        - Use the zero_pad function you implemented above
        - There should be two nested for-loops
        - You may find np.flip() and np.sum() useful

    Args:
        image: numpy array of shape (Hi, Wi).
        kernel: numpy array of shape (Hk, Wk).

    Returns:
        out: numpy array of shape (Hi, Wi).
    """
    Hi, Wi = image.shape
    Hk, Wk = kernel.shape
    out = np.zeros((Hi, Wi))

    ### YOUR CODE HERE
    # numpy.flip reverses the order of array elements along the specified axis, preserving the shape of the array
    # Syntax: numpy.flip(array, axis). We flip horizontally & vertically both
    image = zero_pad(image, Hk//2, Wk//2)
    kernel = np.flip(kernel, 0)
    kernel = np.flip(kernel, 1)
    for m in range(Hi):
        for n in range(Wi):
            out[m, n] =  np.sum(image[m: m + Hk, n: n + Wk] * kernel)
    ### END YOUR CODE
    return out

def conv_faster(image, kernel):
    """
    Args:
        image: numpy array of shape (Hi, Wi).
        kernel: numpy array of shape (Hk, Wk).

    Returns:
        out: numpy array of shape (Hi, Wi).
    """
    Hi, Wi = image.shape
    Hk, Wk = kernel.shape
    out = np.zeros((Hi, Wi))

    ### YOUR CODE HERE
    pass
    ### END YOUR CODE

    return out

# Reference: https://numpy.org/doc/stable/reference/generated/numpy.flip.html

def cross_correlation(f, g):
    """ Cross-correlation of f and g.

    Hint: use the conv_fast function defined above.

    Args:
        f: numpy array of shape (Hf, Wf).
        g: numpy array of shape (Hg, Wg).

    Returns:
        out: numpy array of shape (Hf, Wf).
    """

    out = None
    ### YOUR CODE HERE
    # Flipping the template vertically (,0)
    flippedVertically = np.flip(g, 0)
    # Flipping the template horizontally (,1)
    flippedHorizontally = np.flip(flippedVertically, 1)
    out = conv_fast(f, flippedHorizontally)
    ### END YOUR CODE

    return out

def zero_mean_cross_correlation(f, g):
    """ Zero-mean cross-correlation of f and g.

    Subtract the mean of g from g so that its mean becomes zero.

    Hint: you should look up useful numpy functions online for calculating the mean.

    Args:
        f: numpy array of shape (Hf, Wf).
        g: numpy array of shape (Hg, Wg).

    Returns:
        out: numpy array of shape (Hf, Wf).
    """

    out = None
    ### YOUR CODE HERE
    meanValue = np.mean(g)
    out = cross_correlation(f, g - meanValue)
    ### END YOUR CODE

    return out

# Reference: https://stackoverflow.com/questions/53436231/normalized-cross-correlation-in-python

def normalized_cross_correlation(f, g):
    """ Normalized cross-correlation of f and g.

    Normalize the subimage of f and the template g at each step
    before computing the weighted sum of the two.

    Hint: you should look up useful numpy functions online for calculating 
          the mean and standard deviation.

    Args:
        f: numpy array of shape (Hf, Wf).
        g: numpy array of shape (Hg, Wg).

    Returns:
        out: numpy array of shape (Hf, Wf).
    """

    out = None
    ### YOUR CODE HERE

    Hf, Wf = f.shape
    Hg, Wg = g.shape
    out = np.zeros((Hf, Wf))

    # normalizing the input vectors before using

    g = (g - np.mean(g))/np.std(g)
    f = (f - np.mean(f))/np.std(f)

    img_pad = zero_pad(f, Hg // 2, Wg // 2)

    for i in range(Hf):
        for j in range(Wf):
            img_patch = img_pad[i: i + Hg, j: j + Wg]
            # first part of the eq
            img_normalize = (img_patch - np.mean(img_patch)) / np.std(img_patch)
            out[i, j] = (img_normalize * g).sum()
    ### END YOUR CODE

    return out
