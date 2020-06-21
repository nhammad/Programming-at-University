# JTSK-350111
# a4_p9.py
# nhammad
# n.hammad@jacobs-university.de
 
 
#while True/break ensures that values
#are taken until and unless an invalid
#value is entered
 
s=input("Enter A String= ")
while True:
    a=int(input("Enter 1st Int= "))
    b=int(input("Enter 2nd Int= "))
    if (a>=0 and a<len(s)) and (b>=0 and b<len(s) and b>=a):
        new=s[a:(b+1)]
        print(new)
        break
    else:
        print("Invalid Values, Enter Again")
    
#new=strg[a:(b+1)]:
#^b+1 cause qs says both values should be included
#in if statement: b>=a:
#reverse isn't possible. b should be >=a
