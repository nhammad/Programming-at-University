class Complex(object):
    
     def __init__(self , real, imag):
         self._real = real
         self._imag = imag

     def __str__(self):
          
          if self._imag == 0:
               return (str(self._real))

          # if imag # is positive
          elif self._imag >= 1:
               return (str(self._real) + '+' + str(self._imag) + 'i')

          # neg sign added automatically
          else:
               return (str(self._real) + str(self._imag) + 'i')


     def __add__(self, other):
          ans_real = self._real + other._real
          ans_imag = self._imag + other._imag
          return Complex(ans_real, ans_imag)

     def __sub__(self, other):
          ans_real = self._real - other._real
          ans_imag = self._imag - other._imag
          return Complex(ans_real, ans_imag)

     def __mul__(self, other):
          ans_real = (self._real * other._real) - (self._imag * other._imag)
          ans_imag = (self._real * other._imag) + (self._imag * other._real)
          return Complex(ans_real, ans_imag)

     def __truediv__(self, other):
          real_num = (self._real * other._real) + (self._imag * other._imag)
          real_den = (other._real * other._real) + (other._imag * other._imag)
          imag_num = (self._imag * other._real) - (self._real * other._imag)
          imag_den = (other._real * other._real) + (other._imag * other._imag)
          if real_den and imag_den != 0:              
               new_real = real_num / real_den
               new_imag = imag_num / imag_den
          else:
               raise Exception("Can't Divide by Zero")

     # Overloading ==
     def __eq__(self, other):
        if (self.real == other.real) and (self.imag == other.imag):
            return True
        else:
            return False

     # Overloading !=
     def __ne__(self, other):  
        if (self.real == other.real) and (self.imag == other.imag):
            return False
        else:
            return True


c1 = Complex(2, 3)
c2 = Complex(3, -4)
print("\nc1 + c2 = ", c1 + c2)
print("c1 - c2 = ", c1 - c2)
print("c1 * c2 = ", c1 * c2)
print("c1 / c2 = ", c1 / c2, '\n')
