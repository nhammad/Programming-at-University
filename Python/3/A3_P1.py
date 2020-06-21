# JTSK-350111
# a3_p1.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
char=input()
asc=ord(char)
if asc < 65 or asc > 90:
    print (char, "Is A Lowercase Alphabet ")
else:
    print (char, "Is Not a Lower Case Alphabet")
 
#ord(char)gives the ascii code 
# "A"=65
# "Z"=90
