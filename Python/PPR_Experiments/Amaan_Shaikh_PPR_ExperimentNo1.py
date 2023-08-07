"""
Experiment No 1
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo1.py
"""

print("Enter 1 for 'use arithmetic, logical, bitwise and identity operators'")
print("Enter 2 for 'area  and perimeter of square'")
print("Enter 3 for 'Swap value of 2 variables'")
ch = int(input("Enter your choice: "))

if ch == 1:
    a = int(input("Enter 1st number: "))
    b = int(input("Enter 2nd number: "))
    print("Sum : ", (a + b))
    print("Difference : ", (a - b))
    print("Product : ", (a * b))
    print("Quotient : ", (a / b))
    print("Remainder : ", (a % b))
    if a > 0 and b > 0:
        print("a and b are greater than 0")
    if a < 0 or b < 0:
        print("Either a or b is less than 0")
    if a == 0 and b == 0:
        print("The numbers are greater than 0")
    if not (a % 2 == 0 or a % 5 == 0):
        print(a, " is not divisible by either 2 or 5")
    print("Bitwise AND : ", (a & b))
    print("Bitwise OR : ", (a | b))
    print("Bitwise NOT : ", (~a))
    print("Bitwise NOT : ", (~b))
    print("Bitwise XOR : ", (a ^ b))

elif ch == 2:
    side = int(input("Enter the side: "))
    area = side * side;
    peri = 4 * side;
    print("Area: ", area)
    print("Perimeter: ", peri)
elif ch == 3:
    v1 = int(input("Enter value 1: "))
    v2 = int(input("Enter value 2: "))
    print("Before Swap:")
    print("v1 = ", v1)
    print("v2 = ", v2)
    temp = v1
    v1 = v2
    v2 = temp
    print("After swap:")
    print("v1 = ", v1)
    print("v2 = ", v2)
else:
    print("Wrong choice")
