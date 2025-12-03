#same adjanecy matrix with misplaced elements
#THE ADJANCECNY MATRIX PROGRAM USED FOR CALCULATING THE NO OF MISPLACED TILES
#but here we will use different approach to get a o[nlogn] solution
#WE WILL FLATTEN THE 2D LISTS INTO 1D LISTS AND THEN SORT AND COMPARE THEM
#comic book ass writing bullshit
import itertools

Currentlist = [[1, 2, 3], [4, 7, 5], [6, 0, 8]]
GoalList = [[1, 2, 6], [4, 3, 5], [7, 0, 8]]

# Flatten 2D lists into 1D lists
flattened_list = list(itertools.chain.from_iterable(Currentlist))
flattened_list2 = list(itertools.chain.from_iterable(GoalList))


def compare_lists(a, b):

	length = min(len(a), len(b))
	mismatches = 0
	for i in range(length):
		# If values are equal -> same
		if a[i] == b[i]:
			print(f"Index {i}: {a[i]} == {b[i]} (same)")
		else:
			# Do not count the blank tile (0) as a misplaced tile
			if a[i] == 0 or b[i] == 0:
				print(f"Index {i}: {a[i]} != {b[i]} (blank ignored)")
				# don't increment mismatches
			else:
				print(f"Index {i}: {a[i]} != {b[i]} (different)")
				mismatches += 1

	# Handle extra elements if lists have different lengths
	if len(a) != len(b):
		longer, name = (a, 'first') if len(a) > len(b) else (b, 'second')
		for i in range(length, len(longer)):
			# don't count zeros in the extra part
			if longer[i] == 0:
				print(f"Index {i}: {longer[i]} (only in {name} list - blank ignored)")
			else:
				print(f"Index {i}: {longer[i]} (only in {name} list)")
				mismatches += 1

	return mismatches


if __name__ == '__main__':
	print("Flattened current:", flattened_list)
	print("Flattened goal   :", flattened_list2)
	mismatches = compare_lists(flattened_list, flattened_list2)
	print(f"Total mismatches: {mismatches}")
