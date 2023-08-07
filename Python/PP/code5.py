tup1 = (1,2,3,4,'Panda')
print(tup1)
type(tup1)
tup1 = tup1 + (10,20,30)
print(tup1)

import sys
def tri(a,b,c):
    if(a*a + b*b == c*c):
        print("Right angled triangle")
    else:
        print("Not a right angled triangle ")

try:
    a=float(input("Enter side 1 "))
    b=float(input("Enter side 2 "))
    c=float(input("Enter side 3 "))
    tri(a,b,c)
except:
    print("Error occurred: ",sys.exc_info()[0])