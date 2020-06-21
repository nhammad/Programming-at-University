# JTSK-350111
# a4_p3.py
# nhammad
# n.hammad@jacobs-university.de
 
def to_liter(gallon, cups):
    galliters= (gallons*3.7854)
    cupliters= (cups*0.2366)
    total= galliters+cupliters
    return total
 
#^conversion acc to formulas in qs
#adding to find total volume
    
cups=float(input("Enter Number of Cups= "))
gallons=float(input("Enter Number of Gallons= "))
print("Total Number of Liters= ", to_liter(gallons, cups))
#^calling function and printing
