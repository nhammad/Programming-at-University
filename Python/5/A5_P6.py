# JTSK-350111
# a5_p6.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
def histogram(lst):
    for i in lst:
        print("*"*i)
 
#i in lst:
#here, i is the element itself
#"*" * i multiples the sign i times
 
n=int(input("Enter An Integer Value= "))
lst=[]
for i in range(n):
    f=int(input("Enter Value= "))
    lst.append(f)
histogram(lst)
 
#first, we create an empty list
#append adds value to the end of the list
#after n values are taken, function is called
 
"""Alternative Method for function:
After "for i in list":
        for j in range(i):
            print("*",end="")
        print("\n",end="")"""
