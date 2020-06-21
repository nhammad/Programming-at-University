# JTSK-350111
# a4_p6.py
# nhammad
# n.hammad@jacobs-university.de
 
import random
random . seed ()
minval = 1
maxval = 50
count=0
r = random.randint ( minval , maxval )
while True :
    guess = int( input (" Enter your guess : ") )
    if r == guess :
        print ("You got it!")
        break
    elif guess < r :
        print (" Your guess is too small !")
    else :
        print (" Your guess is too high !")
    count+=1
    print("Number of Tries= ", count)
print("Number of Tries= ", count)
print ("Bye")
 
#count+=1 adds 1 everytime for #of tries
#changed the while not true statement...
#to while True, to be compatible with "break"
#BYE should be outside the while loop
