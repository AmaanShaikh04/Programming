"""
Experiment No 3
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo3.py
"""

print("Enter 1 for 'reverse a number'")
print("Enter 2 for 'print even numbers from 1 to 100'")
print("Enter 3 for 'printing pattern'")
ch = int(input("Enter your choice: "))

if ch == 1:
    n = int(input("Enter number: "))
    rev = 0
    while n > 0:
        dig = n % 10
        rev = rev * 10 + dig
        n = n // 10
    print("Reverse of the number:", rev)

elif ch == 2:
    i = 2
    while i <= 101:
        print(i)
        if i % 10 == 0:
            print("\n")
        i += 2

elif ch == 3:
    k = 1
    space = 2

    while k <= 5:
        print(" " * space, "*" * k)
        k += 2
        space -= 1

    k = 3
    space = 1
    while k >= 1:
        print(" " * space, "*" * k)
        k -= 2
        space += 1
else:
    print("Wrong choice")
