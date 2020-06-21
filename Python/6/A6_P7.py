# JTSK-350111
# a6_p7.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
 
from turtle import Turtle
t=Turtle()
#setting size of screen to 600×600 pixels:
t.screen.setup(width=600, height=600)
 
#defining functions(instructions)
def forward():
    t.forward(10)
def left():
    t.left(15)
def right():
    t.right(15)
def up():
    t.up()
def down():
    t.down()
 
#writing keybord inputs eg 'F'
#and assigning the instruction
jumpTable={}
jumpTable['F']=forward
jumpTable['L']=left
jumpTable['R']=right
jumpTable['U']=up
jumpTable['D']=down
 
while True:
    s=input("Enter String=")
    if s == "": #end when empty string entered
        break
    for i in s:
        jumpTable[i]()
        
#for i in s:
#for each alphabet entered, the for loop
#looks for the coressponding jumpTable line
#and the instruction assigned to it.
#coressponding function is called and turtle
#Moves accordingly
 
 
    
"""def runCommand(s):
    jumpTable[command]()"""
