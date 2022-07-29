

# using a list to represent a stack
stack = []

def push(data):
    print("Pushing ",data)
    stack.append(data)
        

# if we write stack.pop() twice, for ex once while printing,
# it will pop twice.
def pop():
    if isEmpty() == True:
        print("Stack underflow")
    else:
        val = stack.pop()
        print("Popping element", val)
        return val
    

def isEmpty():
    if (stack == []):
        return True
    else:
        return False


# if stack is not empty, we pop until it's empty
def empty():
    if isEmpty()!= True:
        print("Emptying stack")
        while isEmpty() != True:
            print("Popping element ", stack.pop())
    else:
        print("Stack underflow")


# taking input until q is entered
while True:
    ch = input()
    if ch == 'q':
        print("Good Bye!")
        break
    elif ch == 's':
        num = int(input())
        push(num)
    elif ch == 'p':
        pop()
    elif ch == 'e':
        empty()
        
