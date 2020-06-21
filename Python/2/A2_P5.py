# JTSK-350111
# a2_p5.py
# nhammad
# n.hammad@jacobs-university.de
 
mins=int(input("Enter Mins = "))
if mins >=0:
    hours=mins//60
    minsleft=mins%60
    print(mins,"Minutes are equal to", hours,"Hours and", minsleft, "Minutes")
else:
    print("Invalid Input")
 
# %sign gives remainder
# //is for int division. ans is in int
