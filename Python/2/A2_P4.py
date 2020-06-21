# JTSK-350111
# a2_p4.py
# nhammad
# n.hammad@jacobs-university.de
 
#reading a string and converting to float
celc=float(input("Enter Temp in Celcius = "))
#converstion formula
faren=((9/5)*celc*1.0)+32
print("Temp in Farenheit = ", faren)
if faren<32:
    print("It is cold! Temperature is below 32. It is", faren)
elif faren>104:
    print("It is hot! Temperature is above 104. It is", faren)
else:
    print("Normal Temperature!")
