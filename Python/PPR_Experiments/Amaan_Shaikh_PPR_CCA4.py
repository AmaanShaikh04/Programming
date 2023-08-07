"""
CCA 4
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_CCA4.py
"""

print("Enter 1 for 'numpy'")
print("Enter 2 for 'scipy'")
print("Enter 3 for 'matplotlib'")
print("Enter 4 for 'pandas'")
ch = int(input("Enter your choice: "))
if ch == 1:
    import numpy as np

    ar1 = np.array([[1, 2, 3],
                    [4, 2, 5]])
    print("Array is of type: \t", type(ar1))
    print("No. of dimensions: \t", ar1.ndim)
    print("Shape of array: \t", ar1.shape)
    print("Size of array: \t\t", ar1.size)
    print("Type of elements: \t", ar1.dtype)
elif ch == 2:
    import numpy as np

    ar2 = np.array([[1, 0, 1], [0, 1, 0], [1, 0, 1]])
    from scipy import linalg

    linalg.det(ar2)
    print(ar2)
elif ch == 3:
    import matplotlib.pyplot as plt

    a = [5, 15, 22, 35]
    b = [7, 17, 30, 50]
    plt.plot(a, b)
    plt.title("Simple Plot")
    plt.ylabel("b-axis")
    plt.xlabel("a-axis")
    plt.show()
elif ch == 4:
    import pandas as pd

    a = [7, 4, 9]
    print(pd.Series(a))
else:
    print("Wrong choice")




