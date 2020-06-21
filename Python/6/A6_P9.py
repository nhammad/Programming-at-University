# JTSK-350111
# a6_p9.py
# Neeha Hammad
# n.hammad@jacobs-university.de
 
n=int(input("Enter Integer"))
 
lst1=[]
for i in range (n):
    val=int(input())
    lst1.append(val)
 
lst2=[]
for i in range (n):
    val=int(input())
    lst2.append(val)
 
#append(val) adds val to the list.
#changes lists into tupples:
    
v=tuple(lst1)
w=tuple(lst2)
 
#finding scalar product:
def scalar(n,v,w):
    prod=0
    for i in range(n):
        prod += v[i] * w[i]
    print("Scalar Product is",prod)
 
 
scalar(n,v,w)
print("Maximum in V=", max(v))
print("Position=",v.index(max(v)))
print("Maximum in W=", max(w))
print("Position=",w.index(max(w)))
print("Minimum in V=", min(w))
print("Position=",v.index(min(v)))
print("Minimum in W=", min(w))
print("Position=",w.index(min(w)))
 
#w.index(min(w)) returns:
#the position of min number in tuple w
