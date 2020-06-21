# JTSK-350111
# a4_p10.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
#assigning string to variable data:
data="Python is a great programming language"
listOfWords=data.split()
print("Splitting Words= ")
print(listOfWords)
uppercase=data.upper()
print("In Uppercase= ")
print(uppercase)
finding=data.find("programming")
print("Finding Position of Programming= ")
print(finding)
new=data.replace('g', 'G')
print("Replacing= ")
print(new)
 
#.split()separates on basis on new lines/spaces
#.find gives the position of first occurence
#replace('g','G') replaces g with G
