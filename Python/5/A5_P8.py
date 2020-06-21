# JTSK-350111
# a5_p8.py
# nhammad
# n.hammad@jacobs-university.de
 
def overlapping(list1, list2):
    match=0
    for i in list1:
        for j in list2:
            if i==j:
                match+=1
                
    #i in list:i is the element,not position
 
    if match>=1:
        print("The two lists are overlapping.")
    else:
        print("”The two lists are not overlapping.")
 
#match>=1 to see if at least one member is common
        
print("Enter Values for List 1= ")
list1=[]
while True:
    num=int(input())
    if num<0:
        break
    else:
        list1.append(num)
 
print("Enter Values for List 2= ")
list2=[]
while True:
    num2=int(input())
    if num2<0:
        break
    else:
        list2.append(num2)
overlapping(list1,list2)
 
#first empty lists are created
#append adds values to the list
#until a negative value is entered
    
"""Alternative Method for function:
    for i in range(len(list1)):
        for j in range(len(list2)):
            if list1[i]==list2[j]:
                match+=1"""
