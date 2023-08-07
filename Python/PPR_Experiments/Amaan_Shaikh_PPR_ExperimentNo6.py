"""
Experiment No 6
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo6.py
"""

print("Enter 1 for 'dictionary operations'")
print("Enter 2 for 'concatenate dictionaries'")
print("Enter 3 for 'print all unique values in a dictionary'")
ch = int(input("Enter your choice: "))
if ch == 1:
    data = {
        "Name": "Amaan",
        "Age": 18,
        "Year": "Third",
        "Course": "Computer Engineering"
    }
    ch = int(input("What do you want to print?\n1. Name\n2. Age\n3. "
                   "Year\n4. Course\n5. Entire Dictionary\nYour Choice:"))

    if ch == 1:
        print(data["Name"])
        data.update({"Name": "Amaan Shaikh"})
        print("Updated Name to Full name using .update() method")
        print(data["Name"])
    elif ch == 2:
        print(data["Age"])
    elif ch == 3:
        print(data["Year"])
    elif ch == 4:
        print(data["Course"])
    elif ch == 5:
        print("Dictionary: ", data)
    else:
        print("Incorrect argument.")

    data["Favourite Colour"] = "Purple"
    print("\n", data["Favourite Colour"])

    print("\nData keys: ", data.keys())

    del data["Favourite Colour"]
    print("\nUpdated keys: ", data.keys())
    data.clear()  # clears all key-value pairs
    print("\nAfter using .clear() => ", data)
    del data  # deletes the entire dictionary
elif ch == 2:
    d1 = {"One": 1, "Two": 2}
    d2 = {"Three": 3, "Four": 4}
    d3 = {}

    d3.update(d1)
    d3.update(d2)
    print(d3)
elif ch == 3:
    d1 = {2016: "Ronaldo", 2017: "Ronaldo", 2018: "Modric", 2019: "Messi", 2021: "Messi"}
    s1 = set(d1.values())
    print(s1)
else:
    print("Wrong choice")
