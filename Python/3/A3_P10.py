# JTSK-350111
# a3_p10.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
 
def print_frame(length, width, char):
    for i in range (length):
        if i==0:           
            for j in range (width):
                print(char, end = " ")
        elif i==length-1:
            for j in range (width):
                print(char, end = " ")
        else:
            print(char,end = " ")
            for j in range (width-2):
                print(" ",end=" ")
            print(char,end = " ")
        print("\n",end="")
        
n=int(input("Enter First Integer=" ))
m=int(input("Enter Second Integer=" ))
c=input("Enter a Character= ")
print_frame(n, m, c)
 
#if==0: first line
#if==length-1: last line
#else:width-2 cause we already print 2 chars
#^First & last from middle lines.spaces in bw
# end = " " stops it from going to next line
#("\n",end="") prints new line at the end
