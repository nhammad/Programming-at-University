# JTSK-350111
# a6_p5.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
t=Turtle()
t.screen.setup(width=700, height=700)
t.pencolor('orange')
t.up()
#starting point,so that center
#of circle=center of window
t.goto(-140,0)
#turning direction of turtle to south:
t.setheading(270) 
t.down()
#for bigger circle.Radius 140:
t.circle(140)
t.up()
 
#the range is for #of small circles:
for i in range (14):
    t.goto(0,0) #center
    t.left(25)
    t.forward(100)
    t.down()
    t.circle(60)
    t.up()
