# JTSK-350111
# a6_p6.py
# nhammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
t=Turtle()
t.screen.setup(width=700, height=700)
n=int(input("Enter Value of N="))
#range n is for # of stars
for i in range (n):
    t.up()
    t.goto(0,0)
    t.left(360/n)
    t.forward(100)
    t.down()
#left(360/n) to ensure a suitable angle
#to avoid overlapping of stars
    
#range 24 is for #of peaks of a star:
#the following code is for making a single star:
#which will be made n times:
    for i in range(24):
        t.forward(170)
        t.left(165)
    t.end_fill()
    t.hideturtle()
    t.up()
 
#merging codes from 6.4 & 6.5
