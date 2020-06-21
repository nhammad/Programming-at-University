# JTSK-350111
# a4_p5.py
# nhammad
# n.hammad@jacobs-university.de
 
#only imports pi so
#while calling pi, we don't need to add math.
 
from math import (pi)
def calc_volume(r):
    volume=(4/3)*pi*r*r*r
    return volume
 
#calling function and printing
r=float(input("Enter The Radius= "))
print("Volume of Sphere= ", calc_volume(r))
