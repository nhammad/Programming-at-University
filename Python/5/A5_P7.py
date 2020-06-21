# JTSK-350111
# a5_p7.py
# nhammad
# n.hammad@jacobs-university.de
 
print("Enter A List of Numbers= ")
lst=[]
while True:
    num=int(input()) 
    if num==0:
        print("Maximum Value= ",max(lst))
        print("Minimum Value= ", min(lst))
        break
    else:
        lst.append(num)
 
#max(lst) returns max value from list
#first, an empty list is created
#append adds value to the list
#while true/break ensures that values
#are repeatedly taken until 0 is entered
