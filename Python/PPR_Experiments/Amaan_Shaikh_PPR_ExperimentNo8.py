"""
Experiment No 8
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo8.py
"""

print("Enter 1 for 'upper case and lower case count'")
print("Enter 2 for 'area and circum of circle'")
print("Enter 3 for 'random integers between 10 and 30'")
print("Enter 4 for 'college name'")
ch = int(input("Enter your choice: "))


def case_count(str):
    low_ctr = 0
    upp_ctr = 0
    x = 0

    for x in str:
        if x.islower():
            low_ctr += 1
        elif x.isupper():
            upp_ctr += 1

    print("Count of upper case letters: ", upp_ctr)
    print("Count of lower case letters: ", low_ctr)


def clgname():
    clg_name = input("Enter your college name: ")
    print("College name:", clg_name)


if ch == 1:
    str = input("Enter a string: ")
    case_count(str)
elif ch == 2:
    import math as ma

    pi = ma.pi
    rad = int(input("Enter the radius of the circle: "))
    area = pi * rad ** 2
    circum = 2 * pi * rad
    print("Area of the Circle = %0.2f" % area, "sq.units")
    print("Circumference of the Circle = %0.2f" % circum, "units")
elif ch == 3:
    import numpy.random as ran

    ran_list = ran.randint(10, 30, 6)
    print(ran_list)
elif ch == 4:
    clgname()
else:
    print("Wrong choice")
