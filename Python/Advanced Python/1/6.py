

# if len is greater than 0,
# it is not empty
def is_empty(pq):  
    if len(pq) != 0:
        return False
    else:
        return True

#  add the element x to pq with a priority p 
def insert_with_priority(pq, x, p):
    pq.append(tuple((x, p)))
    # sorting by second element i.e priority
    pq.sort(pr = lambda priority: priority[1])  


# Queues work on First In First Out Principle
# we pop the first element(0)
def pull_highest_priority_element(pq):
    if is_empty(pq) == False:
        val = pq.pop(0)  
        return val
    else:
        print ("List is Already Empty")
        return

lst = []  
print("Is List Empty?", is_empty(lst))
insert_with_priority(lst, 5, 2)
insert_with_priority(lst, 3, 3)
insert_with_priority(lst, 13, 1)
insert_with_priority(lst, 6, 1)
print("Current List = ", lst) 
print("Pulling Highest Priority Element = ", pull_highest_priority_element(lst))
print("Current List ", lst)
print("Is List Empty?", is_empty(lst))
print(">> Is it empty?", is_empty(lst))
print("Pulling Highest Priority Element = ", pull_highest_priority_element(lst))
print("Pulling Highest Priority Element = ", pull_highest_priority_element(lst))
print("Pulling Highest Priority Element = ", pull_highest_priority_element(lst))
print("Current List = ", lst) 
print("Is List Empty?", is_empty(lst))
print("Pulling Highest Priority Element = ", pull_highest_priority_element(lst))


