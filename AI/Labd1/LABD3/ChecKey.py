my_dict = {1: "dog", 2: "cat", 3: "dog", 4: "elephant", 5: "cat"}
#check key presence
key=input("Enter key to be searched:")
key=int(key)
if key in my_dict:
    print("Key:", key, "is present in the dictionary.")
    
