# JTSK-350111
# a2_p6.py
# nhammad
# n.hammad@jacobs-university.de
 
string1=input()
int1=int(input())
print("Result:",string1*int1)
# ^this multiplies the string by the int.string repeats int times.
int2=input()
int3=input()
print("Result:",int2+int3)
# ^concatenation of 2 strings
string2=input()
float1=float(input())
print("Result:",string2*float1)
 
#error because 2 diff types are being multiplied
#CORRECTION:
#convert string to float for multiplication
#string2=float(input()) OR
#convert float to int for repetition of string 
#float1=int(input())
