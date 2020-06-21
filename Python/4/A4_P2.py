# JTSK-350111
# a4_p2.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
#defintion of function
#coversion formula in qs
def convert(miles):
    km = miles*1.609344
    return km
 
#function called in main:
miles=float(input("Enter Number of Miles= "))
print("Number of Km= ", convert(miles))
