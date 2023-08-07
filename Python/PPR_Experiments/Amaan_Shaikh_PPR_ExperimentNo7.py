"""
Experiment No 7
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo7.py
"""

print("Enter 1 for 'set operations'")
print("Enter 2 for 'intersection of sets, union of sets, set difference, symmetric difference, clear a set'")
print("Enter 3 for 'create a set, add member(s) in a set and remove one item from set'")
ch = int(input("Enter your choice: "))
if ch == 1:
    set1 = set()
    print(set1, type(set1))

    set1 = {1, 2, 3, 4, 5}
    print("5 in set1: ", 5 in set1)
    print("7 in set1: ", 7 in set1)

    print("\nCurrent Set items:")
    for x in set1:
        print(x)
    print("\nSet: ", set1)

    set1.add(6)
    print("Set after adding: ", set1)

    set2 = {"One", "Two"}
    set3 = [1, 4, 7, 8]
    set1.update(set2)
    print("Set after updating with set2: ", set1)
    set1.update(set3)
    print("Set after updating with set3: ", set1)

    set1.pop()
    print("Set after using pop(): ", set1)

    set1.clear()
    print("Set after clearing: ", set1)

    del set1
elif ch == 2:
    set1 = {1, 2, 3, 4}
    set2 = {1, 5, 6, 7, 8}

    set3 = set1.union(set1, set2)
    print("Union: ", set3)

    set4 = set1.difference(set2)
    print("Difference: ", set4)

    set5 = set1.symmetric_difference(set2)
    print("Symmetric Difference: ", set5)

    set6 = set1.intersection(set2)
    print("Intersection: ", set6)
elif ch == 3:
    set1 = {"One", "Two", "Three"}
    print(set1)
    set1.add("Four")
    print(set1)
    set1.remove("Two")
    print(set1)
else:
    print("Wrong choice")
