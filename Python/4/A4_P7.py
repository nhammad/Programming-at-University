# JTSK-350111
# a4_p7.py
# nhammad
# n.hammad@jacobs-university.de
 
strg=input("Enter A String= ")
for i in range (len(strg)):
    print(" "*i, strg[i], sep="")
 
#if we print without sep,
#there's an extra space bw letters
#" "*i multiplies string by i times
#first space is printed and then letter
#1st position is 0
