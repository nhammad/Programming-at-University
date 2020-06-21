# JTSK-350111
# a3_p8.py
# nhammad
# n.hammad@jacobs-university.de
 
 
sum=0
for i in range(1,11):
    n=int(input("Enter a Number=" ))
    if n == -9:
        avg=sum/(i-1)
        print("The average is"
, avg)
        break
    else:
        sum += n
    if i==10:
        sum += n
        avg=sum/i
        print("The average is"
, avg)
 
#range 1-11 so 10 values are read
#in if: i-1 so -9 isn't included in avg
#computing sum in else is imp
#we need to keep adding sum somewhere
