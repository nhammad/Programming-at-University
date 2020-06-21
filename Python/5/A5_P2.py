# JTSK-350111
# a5_p2.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
f = open("numbers.txt", 'r')
sum=0
for i in f:
    i = i.strip()
    print(i)
    sum+=int(i)
print(sum)
f.close()
 
#if we don't use strip,there's an extra new line
#for loop reads data in all lines
#this ends after all lines finish
