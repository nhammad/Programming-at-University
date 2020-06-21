# JTSK-350111
# a4_p8.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
def count_vowels(s):
    vowels=0
    for vow in s:
        if vow=='a' or vow=='e' or vow=='o' or vow=='u' or vow=='i':
            vowels+=1
    return vowels
 
#vowels=number of vowels.
 
strg=input("Enter A String= ")
while True:
    if strg=="" :
        break
    else:
        print("Number of Vowels= ", count_vowels(strg))
        #to repeatedly enter a string from keyboard:
        strg=input("Enter A String= ")
        
#if strg=="" checks if string is empty
