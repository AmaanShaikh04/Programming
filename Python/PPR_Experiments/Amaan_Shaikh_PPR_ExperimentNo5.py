"""
Experiment No 5
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo5.py
"""
import collections as cl

print("Enter 1 for 'tuple operations'")
print("Enter 2 for 'find repeated items from a tuple'")
print("Enter 3 for 'find min and max in tuple'")
ch = int(input("Enter your choice: "))
if ch == 1:
    print("A module ==>")
    tuple1 = ("New Delhi", "Kabul", "Berlin")
    india = tuple1[0]
    print(india)
    print("Tuple = ", tuple1)
    print("Type of Data = ", type(tuple1))

    tuple_list = list(tuple1)
    print("List converted to tuple =>\n\t", tuple_list, type(tuple_list))
    tuple_list.append("Baghdad")
    print("\t\t", tuple_list)
    tuple_list[1] = "London"
    print("\t\t\t", tuple_list)
    print()
    tuple2 = ("Washington D.C.", "Bangkok")
    tuple2 += tuple1
    print(tuple2)
    del tuple1
elif ch == 2:
    print("\nB module ==>")
    tuple1 = (5,6,8,23,5,3,6)
    tuple_list = list(tuple1)
    set1 = set(tuple_list)
    print(tuple_list)
    print(set1)
    result = len(tuple_list)-len(set1)
    print("\nNumber of repetitions: ", result)
elif ch == 3:
    tuple1 = (4,235,45,3,87,9,223,5,321)
    print("Min: ", min(tuple1))
    print("Max: ", max(tuple1))
else:
    print("Wrong choice")
