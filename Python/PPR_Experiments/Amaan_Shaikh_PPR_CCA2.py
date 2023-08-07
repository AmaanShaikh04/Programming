"""
CCA 2
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_CCA2.py
"""

print("Enter 1 for 'interchange first and last elements in list'")
print("Enter 2 for 'tuple search'")
print("Enter 3 for 'convert list to tuple'")
print("Enter 4 for 'check if key already exists in dictionary'")
print("Enter 5 for 'merge 2 dictionaries'")
print("Enter 6 for 'max and min in set'")
print("Enter 7 for 'remove duplicates in dictionary'")
ch = int(input("Enter your choice: "))
if ch == 1:
    l1 = []
    n = int(input("Enter number of elements: "))
    for i in range(0, n):
        item = input("Enter value: ")
        l1.append(item)
    print("Before Swapping First and Last Element\n",l1, )
    l1[0], l1[-1] = l1[-1], l1[0]
    print("\nAfter Swapping First and Last Element\n",l1)
elif ch == 2:
    t1 = ()
    n = int(input("Enter number of elements: "))
    t1 = list(t1)
    for i in range(0, n):
        item = input("Enter value: ")
        t1.append(item)
    t1 = tuple(t1)
    se = input("Enter item to search in tuple: ")
    if se in t1:
        print("Item Found")
    else:
        print("Item not Found")
elif ch == 3:
    l2 = []
    n = int(input("Enter number of elements: "))
    for i in range(0, n):
        item = input("Enter value: ")
        l2.append(item)
    print("List:", l2, "\nTuple:", tuple(l2))
elif ch == 4:
    d1 = {}
    n = int(input("Enter the number of keys and values: "))
    for i in range(0, n):
        key = input("Enter key: ")
        value = input("Enter value: ")
        d1[key] = value
    key_s = input("Enter Key to search in the dictionary: ")
    if key_s in d1.keys():
        print("Key Found")
    else:
        print("Key not Found")
elif ch == 5:
    d2 = {}
    n = int(input("Enter the number of keys and values in first dictionary: "))
    for i in range(0, n):
        key = input("Enter key: ")
        value = input("Enter value: ")
        d2[key] = value
    d3 = {}
    n = int(input("Enter the number of keys and values in second dictionary: "))
    for j in range(0, n):
        key = input("Enter key: ")
        value = input("Enter value: ")
        d3[key] = value
    print("First Dictionary: ", d2, "\nSecond Dictionary: ", d3)
    d2.update(d3)
    print("Merged Dictionary: ", d2)
elif ch == 6:
    s1 = set()
    n = int(input("Enter number of elements: "))
    for i in range(0, n):
        item = input("Enter value: ")
        s1.add(item)
    print(s1)
    print("Minimum in set: ", min(s1))
    print("Maximum in set: ", max(s1))
elif ch == 7:
    d4 = {}
    n = int(input("Enter the number of keys and values: "))
    for i in range(0, n):
        key = input("Enter key: ")
        value = input("Enter value: ")
        d4[key] = value

    temp = []
    d5 = {}
    for key, val in d4.items():
        if val not in temp:
            temp.append(val)
            d5.update({key: val})
    print(d5)
else:
    print("Wrong choice")
