# JTSK-350111
# a6_p8.py
# nhammad
# n.hammad@jacobs-university.de
 
dict={"merry":"god", "christmas":"jul", "and":"och", "happy":"gott",
"new":"nytt", "year":"\u00E5r"}
#\u00E5 is a code for a special character
 
def translate(list_en):
    swedish=''
    for i in list_en:
        swedish=dict[i]
        print(swedish)
 
#first, an swedish is set as empty[]
#for i in list_en:
#for each word in the list, the corresponding
#word is returned from the directory
 
greet=input("Enter List of English Words= ")
lst_en=greet.split()
translate(lst_en)
 
#split changes the input into a list.
