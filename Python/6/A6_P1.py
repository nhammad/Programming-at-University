# JTSK-350111
# a6_p1.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
#defining t first
t=Turtle()
t.screen.setup(width=600, height=600)
side=int(input("Enter Side Length=" ))
def square(t,length):
    t.up()
    t.forward(side/2)
    t.left(90)
    t.down()
    t.forward(side/2)
    t.left(90)
    t.forward(side)
    t.left(90)
    t.forward(side)
    t.left(90)
    t.forward(side)
    t.left(90)
    t.forward(side/2)
    t.hideturtle()
 
square(t,side)
 
#when t.up(),nothing is drawn.
#when t.down(),line's drawn.
