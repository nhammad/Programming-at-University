import numpy as np
import scipy.stats as st
from scipy import signal
import scipy.ndimage.filters as fi
import math
from collections import deque

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
# numpy.flip reverses the order of array elements along the specified axis, preserving the shape of the array
# Syntax: numpy.flip(array, axis). We flip horizontally & vertically both
# Reusing conv_fast code from previous hw

def conv(image, kernel):
    """ An implementation of convolution filter.

    This function uses element-wise multiplication and np.sum()
    to efficiently compute weighted sum of neighborhood at each
    pixel.

    Args:
        image: numpy array of shape (Hi, Wi).
        kernel: numpy array of shape (Hk, Wk).

    Returns:
        out: numpy array of shape (Hi, Wi).
    """
    Hi, Wi = image.shape
    Hk, Wk = kernel.shape
    out = np.zeros((Hi, Wi))

    # For this assignment, we will use edge values to pad the images.
    # Zero padding will make derivatives at the image boundary very big,
    # whereas we want to ignore the edges at the boundary.
    pad_width0 = Hk // 2
    pad_width1 = Wk // 2
    pad_width = ((pad_width0,pad_width0),(pad_width1,pad_width1))
    padded = np.pad(image, pad_width, mode='edge')

    ### YOUR CODE HERE
    kernel = np.flip(kernel, 0)
    kernel = np.flip(kernel, 1)
    for m in range(Hi):
        for n in range(Wi):
            out[m, n] =  np.sum(padded[m: m + Hk, n: n + Wk] * kernel)
    ### END YOUR CODE
    return out

def gaussian_kernel(size, sigma):
    """ Implementation of Gaussian Kernel.

    This function follows the gaussian kernel formula,
    and creates a kernel matrix.

    Hints:
    - Use np.pi and np.exp to compute pi and exp.

    Args:
        size: int of the size of output matrix.
        sigma: float of sigma to calculate kernel.

    Returns:
        kernel: numpy array of shape (size, size).
    """

    kernel = np.zeros((size, size))

    ### YOUR CODE HERE
    k = size // 2
    for i in range(size):
        for j in range(size):
            # second part of the eq
            numeratorForExponent =  - ((i - k) ** 2 + (j - k) ** 2)
            denomentorForExponent = 2 * sigma ** 2
            forExponent = numeratorForExponent / denomentorForExponent
            # first part of the eq * exponent component
            kernel[i][j] = float(1) / (float(2) * math.pi * sigma ** 2) * math.exp(forExponent)

    ### END YOUR CODE

    return kernel

def partial_x(img):
    """ Computes partial x-derivative of input img.

    Hints:
        - You may use the conv function in defined in this file.

    Args:
        img: numpy array of shape (H, W).
    Returns:
        out: x-derivative image.
    """

    out = None

    ### YOUR CODE HERE
    # Array becomes like this: ([[0, 0, 0], [0.5, 0, -0.5], [0, 0, 0]])
    # We select values of Dx by looking at the test input
    DxKernel = np.array([0.5, 0, -0.5]).reshape((1, 3))
    out = conv(img, DxKernel)
    ### END YOUR CODE

    return out

def partial_y(img):
    """ Computes partial y-derivative of input img.

    Hints:
        - You may use the conv function in defined in this file.

    Args:
        img: numpy array of shape (H, W).
    Returns:
        out: y-derivative image.
    """

    out = None

    ### YOUR CODE HERE
    # We select values of Dy by looking at the test input
    DyKernel = np.array([0.5, 0, -0.5]).reshape((3, 1))
    out = conv(img, DyKernel)
    ### END YOUR CODE

    return out

def gradient(img):
    """ Returns gradient magnitude and direction of input img.

    Args:
        img: Grayscale image. Numpy array of shape (H, W).

    Returns:
        G: Magnitude of gradient at each pixel in img.
            Numpy array of shape (H, W).
        theta: Direction(in degrees, 0 <= theta < 360) of gradient
            at each pixel in img. Numpy array of shape (H, W).

    Hints:
        - Use np.sqrt and np.arctan2 to calculate square root and arctan
    """
    G = np.zeros(img.shape)
    theta = np.zeros(img.shape)

    ### YOUR CODE HERE
    xPartialDerivative = partial_x(img)
    yPartialDerivative  = partial_y(img)

    G = np.sqrt(xPartialDerivative ** 2 + yPartialDerivative  ** 2)

    thetaInRadians = np.arctan2(yPartialDerivative, xPartialDerivative)
    theta = (np.rad2deg(thetaInRadians) + 180) % 360
    ### END YOUR CODE

    return G, theta

# Reference: https://towardsdatascience.com/canny-edge-detection-step-by-step-in-python-computer-vision-b49c3a2d8123

def non_maximum_suppression(G, theta):
    """ Performs non-maximum suppression.

    This function performs non-maximum suppression along the direction
    of gradient (theta) on the gradient magnitude image (G).

    Args:
        G: gradient magnitude image with shape of (H, W).
        theta: direction of gradients with shape of (H, W).

    Returns:
        out: non-maxima suppressed image.
    """
    H, W = G.shape
    out = np.zeros((H, W))

    # Round the gradient direction to the nearest 45 degrees
    theta = np.floor((theta + 22.5) / 45) * 45

    ### BEGIN YOUR CODE
    for i in range(H-1):
        for j in range(W-1):
            angle = np.deg2rad(theta[i, j])
            sinValue = int(np.round(np.sin(angle)))
            cosValue = int(np.round(np.cos(angle)))
            # strengths of edges next to the current i,j pixel/cell
            strength1 = G[i - sinValue, j - cosValue]
            strength2 = G[i + sinValue, j + cosValue]
            # checking edge strengths 
            if not (G[i, j] >= strength1 and G[i, j] >= strength2):
                # If the edge strength of the current pixel is smaller than it's corresponding pixels, 
                # supressing the value
                out[i, j] = 0
            # If the edge strength of the current pixel is the largest, preserve the value of the edge strength.
            else:
                out[i, j] = G[i, j]
    ### END YOUR CODE
    return out


def double_thresholding(img, high, low):
    """
    Args:
        img: numpy array of shape (H, W) representing NMS edge response.
        high: high threshold(float) for strong edges.
        low: low threshold(float) for weak edges.

    Returns:
        strong_edges: Boolean array representing strong edges.
            Strong edeges are the pixels with the values greater than
            the higher threshold.
        weak_edges: Boolean array representing weak edges.
            Weak edges are the pixels with the values smaller or equal to the
            higher threshold and greater than the lower threshold.
    """

    strong_edges = np.zeros(img.shape, dtype=np.bool)
    weak_edges = np.zeros(img.shape, dtype=np.bool)

    ### YOUR CODE HERE
    weak_edges = (img < high) & (img > low)
    strong_edges = img > high
    ### END YOUR CODE

    return strong_edges, weak_edges


def get_neighbors(y, x, H, W):
    """ Return indices of valid neighbors of (y, x).

    Return indices of all the valid neighbors of (y, x) in an array of
    shape (H, W). An index (i, j) of a valid neighbor should satisfy
    the following:
        1. i >= 0 and i < H
        2. j >= 0 and j < W
        3. (i, j) != (y, x)

    Args:
        y, x: location of the pixel.
        H, W: size of the image.
    Returns:
        neighbors: list of indices of neighboring pixels [(i, j)].
    """
    neighbors = []

    for i in (y-1, y, y+1):
        for j in (x-1, x, x+1):
            if i >= 0 and i < H and j >= 0 and j < W:
                if (i == y and j == x):
                    continue
                neighbors.append((i, j))

    return neighbors

# Reference: https://towardsdatascience.com/canny-edge-detection-step-by-step-in-python-computer-vision-b49c3a2d8123

def link_edges(strong_edges, weak_edges):
    """ Find weak edges connected to strong edges and link them.

    Iterate over each pixel in strong_edges and perform breadth first
    search across the connected pixels in weak_edges to link them.
    Here we consider a pixel (a, b) is connected to a pixel (c, d)
    if (a, b) is one of the eight neighboring pixels of (c, d).

    Args:
        strong_edges: binary image of shape (H, W).
        weak_edges: binary image of shape (H, W).
    
    Returns:
        edges: numpy boolean array of shape(H, W).
    """

    H, W = strong_edges.shape
    indices = np.stack(np.nonzero(strong_edges)).T
    edges = np.zeros((H, W), dtype=np.bool)

    # Make new instances of arguments to leave the original
    # references intact
    weak_edges = np.copy(weak_edges)
    edges = np.copy(strong_edges)

    ### YOUR CODE HERE
    # Iterating over each pixel in strong_edges
    for x in range(0, H):
        for y in range(0, W):
            if strong_edges[x, y]:
                q = deque([(x, y)])
                while len(q) > 0:
                    i, j = q.pop()
                    # getting neighbors 
                    for a, b in get_neighbors(i, j, H, W):  
                        # if a pixel is present in weak_edges but it is not one of the 8 neighbors, it's not linked
                        if weak_edges[a, b] and not edges[a, b]:
                            edges[a, b] = True
                            q.appendleft((a, b))
    ### END YOUR CODE

    return edges

def canny(img, kernel_size=5, sigma=1.4, high=20, low=15):
    """ Implement canny edge detector by calling functions above.

    Args:
        img: binary image of shape (H, W).
        kernel_size: int of size for kernel matrix.
        sigma: float for calculating kernel.
        high: high threshold for strong edges.
        low: low threashold for weak edges.
    Returns:
        edge: numpy array of shape(H, W).
    """
    ### YOUR CODE HERE
    kernel = gaussian_kernel(kernel_size, sigma)
    smoothed = conv(img, kernel)
    G, theta = gradient(smoothed)
    supressed = non_maximum_suppression(G, theta)
    strong_edges, weak_edges = double_thresholding(supressed, high, low)
    edge = link_edges(strong_edges, weak_edges)
    ### END YOUR CODE

    return edge


def hough_transform(img):
    """ Transform points in the input image into Hough space.

    Use the parameterization:
        rho = x * cos(theta) + y * sin(theta)
    to transform a point (x,y) to a sine-like function in Hough space.

    Args:
        img: binary image of shape (H, W).
        
    Returns:
        accumulator: numpy array of shape (m, n).
        rhos: numpy array of shape (m, ).
        thetas: numpy array of shape (n, ).
    """
    # Set rho and theta ranges
    W, H = img.shape
    diag_len = int(np.ceil(np.sqrt(W * W + H * H)))
    rhos = np.linspace(-diag_len, diag_len, int(diag_len * 2.0 + 1))
    thetas = np.deg2rad(np.arange(-90.0, 90.0))

    # Cache some reusable values
    cos_t = np.cos(thetas)
    sin_t = np.sin(thetas)
    num_thetas = len(thetas)

    # Initialize accumulator in the Hough space
    accumulator = np.zeros((2 * diag_len + 1, num_thetas), dtype=np.uint64)
    ys, xs = np.nonzero(img)

    # Transform each point (x, y) in image
    # Find rho corresponding to values in thetas
    # and increment the accumulator in the corresponding coordiate.
    ### YOUR CODE HERE
    pass
    for y, x in zip(ys, xs):
        for i in range(num_thetas):
            cos_theta = cos_t[i]
            sin_theta = sin_t[i]
            p = int(round((x * cos_theta) + (y * sin_theta)))
            p_idx = (np.abs(rhos - p)).argmin()
            accumulator[p_idx][i] += 1

    return accumulator, rhos, thetas

