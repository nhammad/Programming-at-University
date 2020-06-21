# JTSK-350111
# a6_p4.py
# nhammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
t=Turtle()
t.screen.setup(width=600, height=600)
 
t.up()
t.goto(-100,-100) #starting point
t.down()
t.pencolor('red')
t.fillcolor('purple')
t.begin_fill()
#for filling color
 
#this range is for # of peaks
for i in range(18):
    t.forward(170)
    t.left(170)
t.end_fill()
t.hideturtle()
#hideturtle to hide cursor at the end
#left(170)=170 is the angle of rotation
 
 
 
 
"""
t.goto(-50,100)
t.goto(0,-100)
t.goto(-200,0)
t.goto(100,0)
t.goto(-100,-100)"""
