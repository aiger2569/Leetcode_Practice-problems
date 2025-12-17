my_dict = {1: "dog", 2: "cat", 3: "dog", 4: "elephant", 5: "cat"}
value_frequencies = {}

for value in my_dict.values():
    # Get the current count (or 0 if the value is new) and increment it by 1
    value_frequencies[value] = value_frequencies.get(value, 0) + 1

print(value_frequencies)