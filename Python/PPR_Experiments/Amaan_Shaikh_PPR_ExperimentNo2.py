"""
Experiment No 2
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo2.py
"""

print("Enter 1 for 'check leap year'")
print("Enter 2 for 'grade 5 subjects'")
print("Enter 3 for 'max among 3 numbers'")
ch = int(input("Enter your choice: "))

if ch == 1:
    yr = int(input("Enter Year\n"))
    if yr < 0:
        print("Invalid year entered")
    if yr % 4 == 0 and yr % 100 != 0 or yr % 400 == 0:
        print("Leap year")
    else:
        print("Not a Leap year")

elif ch == 2:
    m1 = int(input("Enter marks out of 100 of subject 1: "))
    m2 = int(input("Enter marks out of 100 of subject 2: "))
    m3 = int(input("Enter marks out of 100 of subject 3: "))
    m4 = int(input("Enter marks out of 100 of subject 4: "))
    m5 = int(input("Enter marks out of 100 of subject 5: "))
    grade = ""
    if m1 > 100 or m1 < 0 or m2 > 100 or m2 < 0 or m3 > 100 or m3 < 0 or m4 > 100 or m4 < 0 or m5 > 100 or m5 < 0:
        print("Enter valid marks")
    else:
        tot = m1 + m2 + m3 + m4 + m5
        per = (tot / 500) * 100
        if 75 <= per <= 100:
            grade = "A"
        elif 40 <= per <= 74:
            grade = "B"
        elif 0 <= per <= 39:
            grade = "F"
        print("Percent : ", per)
        print("Grade : ", grade)

elif ch == 3:
    n1 = int(input("Enter number 1: "))
    n2 = int(input("Enter number 2: "))
    n3 = int(input("Enter number 3: "))
    max = 0

    if n1 > n2 and n1 > n3:
        max = n1;
    elif n2 > n1 and n2 > n3:
        max = n2
    elif n3 > n1 and n3 > n2:
        max = n3
    print("Max = ", max)
else:
    print("Wrong choice")
