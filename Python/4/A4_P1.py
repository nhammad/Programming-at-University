# JTSK-350111
# a4_p1.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
strg=input("Enter A String= ")+'\n'
count=0
while True:
    if strg[count] == '\n':
        break
    else:
        count+=1        
print(count)
 
#new line(\n) was added so end of line can be determined
#count is string of length
#while true: keeps running until it breaks
