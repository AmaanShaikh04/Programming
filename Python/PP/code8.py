import numpy as np
a = np.array([1, 2, 3, 4, 5])
print(a)
print(type(a))

# 0-D Array
arr = np. array (42)
print("Dimensions: ",arr.ndim)
print(arr)
# 1-D Array
arr1 = np.array([1, 2, 3, 4, 5])
print("Dimensions: ",arr1.ndim)
print(arr1)
# 2-D Array
arr2 = np.array([[1, 2, 3], [4, 5,6]])
print("Dimensions: ",arr2.ndim)
print(arr2)
# 3-D Array
arr3 = np.array([[[0, 1], [2, 3]],[[4, 5], [6, 7]]])
print("Dimensions: ",arr3.ndim)
print(arr3)

x1= np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
print("Shape: ",x1.shape)
x1=x1.reshape(4 ,2)
print("Reshape: \n",x1)
y1 = np.array([1,2,3,4,5,6])
y1 = y1.reshape(3,2)
print("Reshape 1-D array to 2-D array: \n",y1)

a1 = np.array([(1 ,2 ,3)])
print (a.dtype)
# Print the array after changing the data type
a1 = a1.astype('float64')
print(a1)
print(a1.dtype)
s = np.array(['ABC', 'XYZ', '123'])
print(s.dtype)

b = np.arange(1, 10, 2)
print(b)
c = np.linspace(0, 1, 6)
print(c)

x = np. array ([(8 ,9 ,10) ,(11 ,12 ,13) ])
y =np. array ([(1 ,2 ,3) ,(4, 5 ,6) ])
print("Add Arrays: \n",x+y)
print("Add Arrays: \n",np.add(x,y))
print("Subtract Arrays: \n",np.subtract(x,y))
print("Add Array Elements: \n",np.sum(x))
print("Add Array Column Elements: \n",np.sum(x,axis=0))
print("Add Array Row Elements: \n",np.sum(x,axis=1))