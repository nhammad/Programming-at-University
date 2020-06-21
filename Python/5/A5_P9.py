# JTSK-350111
# a5_p9.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
def longest_word(lst):
    long=[]
    for word in lst:
        if len(word)>len(long):
            long=word
    return long,len(long)
 
#first, long=[] is initialized as empty
#word in lst:
#here, word is an element from lst
#In for loop: if length of word is > than 
#the previous one, the "long" word is changed
    
data=input("Enter A String= ")
lst=data.split()
#creating a tuple from the values returned by func
(word, length) = longest_word(lst)
print("The longest word is",word,". It's length is",length)
 
    
#split()creates a list of elements from entered string
