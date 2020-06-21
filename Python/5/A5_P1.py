# JTSK-350111
# a5_p1.py
# nhammad
# n.hammad@jacobs-university.de
 
f = open("input.txt", 'r')
content = f.read()
code1=ord(content[0])
code2=ord(content[1])
prod=code1*code2
f.close()
f = open (" output .txt", 'w')
f.write(str(prod))
f.close()
 
 
#ord returns the ascii code
#'r'=read.'w'=write.
#if we close file before opening new one,
#we can use the same name (f)
#while writing, we convert to string
