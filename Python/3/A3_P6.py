# JTSK-350111
# a3_p6.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
ch=input()
n=int(input())
print(ch)
i = 1
while (i < n+1):  
    ch=chr(ord(ch)+1)
    print(ch)
    i+=1
 
#ord gives ascii code
#+1 adds one number to the code
#we move to the code of next character
#chr() changes back to a character
#first print(ch) prints the initial char
#print(ch) in the loop prints new char
