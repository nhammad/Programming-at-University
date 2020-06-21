# JTSK-350111
# a3_p7.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
 
ok = False
while not ok :
    ch = input("Enter an uppercase character= ")
    if 'A' <= ch <= 'Z':
        ok = True
    else:
        print("Not uppercase , enter again")
 
ok = False
while not ok :
    n=int(input("Enter A Number= "))
    if n >= 0 and n<= 32:
        ok = True
    else:
        print("Invalid Number, enter again")
 
 
print(ch)
i = 1
while (i < n+1):  
    ch=chr(ord(ch)+1)
    print(ch)
    i+=1
        
#input should be taken in the loop
#until if condition is fulfilled,loop keeps repeating
#input will be taken until if condition is true
