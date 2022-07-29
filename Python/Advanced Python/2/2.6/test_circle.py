
from circle import Circle
# test_circle.py

# Creating Circle Objects
# 2nd has no parameters so it takes
# default values

circle1 = Circle(3.00, "Orange")
circle2 = Circle()

# Checking overloading
print("Adding Areas of 2 circles (Sum) = ", circle1 + circle2)
print("Subtracting Areas of 2 circles (Diff) = ", circle1 + circle2)

# Checking get methods
print("Radius of Circle 1 = ", circle1.getRadius())
print("Color of Circle 1 = ", circle1.getColor())

# Checking set methods
circle2.setColor("Pink")
print("Color of Circle 2 After Changing = ", circle2.getColor())

circle1.setRadius(4.11)
print("Radius of Circle 1 = ", circle1.getRadius())
