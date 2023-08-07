"""
Experiment No 10
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo10.py
"""

print("Enter 1 for 'password check'")
print("Enter 2 for 'area of square and rectangle'")
ch = int(input("Enter your choice: "))
if ch == 1:
    try:
        user = input('Enter your username: ')
        paswd = input('Enter your password: ')
        if user == 'amaan' and paswd == 'amaan123':
            print("Welcome back", user, "\b!")
        else:
            raise Exception()
    except Exception:
        print("Wrong Username or Password")
elif ch == 2:
    ch = int(input('1. Area of Rectangle\n2. Area of Square\n\nYour Choice: '))
    if ch == 1:
        l = int(input('Enter Length of rectangle: '))
        b = int(input('Enter Breadth of rectangle: '))
        print("area = ", l * b)

    elif ch == 2:
        s = int(input("Enter side of square: "))
        print("area = ", s * s)
else:
    print("Wrong choice")
