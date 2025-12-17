prop=[1, 2, 3, 4, 5]

prop.insert(0, 10)
print(prop)  # Output: [10, 2, 3, 4, 5]# Example of a list property in Python
#to delete
prop.remove(10)
print(prop)  # Output: [1,2, 3, 4, 5]
#search a element
index = prop.index(3)
print(index)  # Output: 2
#print the searched element
print(prop[index])