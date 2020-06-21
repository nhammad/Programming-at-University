# JTSK-350111
# a6_p3.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
t=Turtle()
t.screen.setup(width=700, height=700)
radius=float(input("Enter the Radius= "))
def square(t,x,y,side=200):
    t.up()
    t.goto(x,y)
    t.down()
    t.pencolor('orange')
    for count in range(4):
        t.forward(side)
        t.left(90)
 
#side=200 already assigned for the sqaure.
#calling function to create a square:
square(t,0,0)
t.pencolor('orange')
t.up()
t.goto(radius,0)
t.down()
t.circle(radius)
t.up()
#coordinates of where circle drawing should start
t.goto(200-radius,0) 
t.down()
#built in function:
t.circle(radius)
t.up()
t.goto(200-radius,200-(2*radius))
t.down()
t.circle(radius)
t.up()
t.goto(0+radius,200-(2*radius))
t.down()
t.circle(radius)
