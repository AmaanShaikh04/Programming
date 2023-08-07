list = []
print(list)
list1 = [1,2,3,'Panda','Harsh', 'Hello']
print(list1)

list.append([10,100])
print(list)
list.extend(["ABC","XYZ","Hii"])
print(list)
list.insert(1, 'Hii')
print(list)

del list[0]
print(list)
list.remove('Hii')
print(list)
print(list.pop())

list.clear()
print(list)