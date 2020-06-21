# JTSK-350111
# a3_p9.py
# nhammad
# n.hammad@jacobs-university.de
 
#function definition:
def print_rectangle(length, width, char):
    for i in range (length):
        for j in range (width):
            print(char, end = " ")
        print("\n",end="")
 
#end = " " stops it from going to next line
#new line printed at the end
 
n=int(input("Enter First Integer=" ))
m=int(input("Enter Second Integer=" ))
c=input("Enter a Character= ")
#calling function now:
print_rectangle(n, m, c)
