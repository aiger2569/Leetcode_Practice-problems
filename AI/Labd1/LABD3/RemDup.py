#to remove duplicates from a list
def remDup(input_list):
    return list(set(input_list))


li = [1, 2, 2, 3, 4, 4, 5]
print("Original List:", li)
print("List after removing duplicates:", remDup(li))