x = int(input("Enter Number 1 "))
y = int(input("Enter Number 2 "))
z = int(input("Enter Number 3 "))
if x>y and x>z:
    print(x, "is greatest")
elif y>x and y>z:
    print(y, "is greatest")
else:
    print(z, "is greatest")

x = input("Enter String 1: ")
y = input("Enter String 2: ")
a = "Hello this is a"
b = '''This is b'''
c = 'Hello this is c'
d = """Hello this is Panda"""
print(type(x))
print(x,y,a,b,c,d)

print("When y is joined with x :",x.join(y))