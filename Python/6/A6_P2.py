# JTSK-350111
# a6_p2.py
# nhammad
# n.hammad@jacobs-university.de
 
from turtle import Turtle
t=Turtle()
t.screen.setup(width=700, height=700)
side=int(input("Enter Side Length=" ))
def square(t,x,y,side):
    t.up()
    t.goto(x,y)
    t.down()
    t.pencolor('green')
    for count in range(4):
        t.forward(side)
        t.left(90)
        
#down()starts the pen
#pencolor changes color
#calling function 5 times
        
square(t,0,0,200)
square(t,0,0,side)
square(t,200-side,0,side)
square(t,200-side,200-side,side)
square(t,0,200-side,side)
 
#without -side, the small sqaures would start
#from edge and will be drawn outside big box
