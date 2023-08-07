import threading
def square(l1):
    for i in l1:
        print("Square = " , i**2)
def cube(l1):
    for i in l1:
        print("Cube = " , i**3)

l1=[3,4,2,5,6,7]
t1 = threading.Thread(target=square, args=(l1,))
t2 = threading.Thread(target=cube, args=(l1,))
t1.start()
t2.start()
t1.join()
t2.join()