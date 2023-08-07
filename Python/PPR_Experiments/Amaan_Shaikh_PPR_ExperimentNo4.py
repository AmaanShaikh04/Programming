"""
Experiment No 4
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo4.py
"""

print("Enter 1 for 'list operations'")
print("Enter 2 for 'print even items from a list'")
print("Enter 3 for 'find common items in 2 lists'")
ch = int(input("Enter your choice: "))
if ch == 1:
    list1 = []
    print(list1)
    list2 = ["New Delhi", "Kabul", "Berlin", "Baghdad", "London"]
    print(list2)
    print("Type of Data = ", type(list2))
    india = list2[0]
    iraq = list2[-2]
    print("India = ", india, "\tIraq = ", iraq)

    print("\nAdding 'Washington D.C.': ")
    list2.append("Washington D.C.")
    print(list2)

    print("Adding 'Bangkok' at index[3]: ")
    list2.insert(3, "Bangkok")
    print(list2)

    print("Adding another list: ")
    list2_2 = ["Abu Dhabi", "Riyadh", "Muscat"]
    list2.extend(list2_2)
    print(list2)

    print("\nRemoving 3rd value using del: ")
    del list2[2]
    print(list2)
    print("Removing 4th value using pop: ")
    list2.pop(4)
    print(list2)
    print("Removing 'Bangkok': ")
    list2.remove("Bangkok")
    print(list2)
elif ch == 2:
    list2 = [1, 2, 3, 4, 5, 6, 22]
    list3 = [x for x in list2 if (x % 2 == 0)]
    print(list3)
elif ch == 3:
    a = [1, 2, 3, 4, 5]
    b = [1, 7, 4, 9]
    a_set = set(a)
    b_set = set(b)

    if (a_set & b_set):
        print(a_set & b_set)
    else:
        print("No common elements")
else:
    print("Wrong choice")

