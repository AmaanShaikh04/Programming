class Student:
    avg=0
    def __init__(self, name, roll, m1, m2, m3):
        self.name = name
        self.roll = roll
        self.m1 = m1
        self.m2 = m2
        self.m3 = m3

    # Instance method
    def passFail(self):
        avg = (self.m1+self.m2+self.m3)/3
        print("Name: ",self.name)
        print("Roll No.: ",self.roll)
        print("Subject 1: ",self.m1)
        print("Subject 2: ",self.m2)
        print("Subject 3: ",self.m3)
        if avg > 50:
            print("Result: Pass")
        else:
            print("Result: Fail")

name=input("Enter Name ")
roll=int(input("Enter Roll No. "))
m1=int(input("Enter marks of subject 1 "))
m2=int(input("Enter marks of subject 2 "))
m3=int(input("Enter marks of subject 3 "))

stu1 = Student(name, roll, m1, m2, m3)
stu1.passFail()