
from math import pi

class Circle(object):

     # default values for parameters
     # protected variables
    def __init__(self , radius = 1.0, color = "red"): 
         self._radius = radius
         self._color = color
         
    def getRadius(self):
        return self._radius
     
    def getColor(self):
        return self._color

    def setRadius(self, radius):
        self._radius = radius

    def setColor(self, color):
        self._color = color

    # Area of circle = pi * r * r
    def getArea(self):  
        return pi * self._radius * self._radius

    # Perimeter of circle = 2 * pi * r
    def getPerimeter(self):   
        return 2 * pi * self.__radius

    # Overloading of operators
    # Adds the areas of 2 circles. Note: It's not creating
    # a new circle
    def __add__(self, other):  
        return self.getArea() + other.getArea()


    # Subtracts the areas of 2 circles.
    def __sub__(self, other):
        return self.getArea() - other.getArea()


"""cir1 = Circle(3, "Orange")
cir2 = Circle()
ans = cir1 + cir2
print(ans)"""
