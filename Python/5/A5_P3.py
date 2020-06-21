# JTSK-350111
# a5_p3.py
# nhammad
# n.hammad@jacobs-university.de
 
file=input("Enter The File Name")
f = open(file, 'r')
count = 0
for i in f:
    i=i.strip()
    words = i.split()
    count += 1
    print("Number Of Words in Line",count, "is", len(words))
    
 
#when i in f:
#i is the element in f.not position.
#strip gets rid of extra spaces from start/end
#split:changes elements of string into list(word)
#count=Line number
#len(words)=number of elements in the list
