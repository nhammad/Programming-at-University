# JTSK-350111
# a5_p4.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
file=input("Enter The File Name")
f = open(file, 'r')
#reading the file content
#&assigning it to "content"
content=f.read()
f.close()
#new file automatically created:
f = open("copy.txt", 'w')
f.write(str(content))
f.close()
 
#if we close the file early, we can reuse name
#only strings can be written in txt files
#so we say  f.write(str(content))
