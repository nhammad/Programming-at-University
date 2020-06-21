# JTSK-350111
# a5_p5.py
# nhammad
# n.hammad@jacobs-university.de
 
def add(lst, val):
    for i in range(len(lst)):
        lst[i]+=val
    return lst
def multiply(lst, val):
    print(val)
    for i in range(len(lst)):
        lst[i]*=val
    return lst
#when i in range len(lst):
#i is the index/position
#when i is lst: i is the element
 
n=int(input("Enter An Integer Value= "))
lst1=[]
lst2=[]
for i in range(n):
    f=float(input("Enter A Float Value= "))
    lst1.append(f)
    lst2.append(f)
print(add(lst1,1.5))
print(multiply(lst2,5))
 
#lst1.append(f):
#adds f's value to the end of lst1
#2 lists created to avoid mixing of results
