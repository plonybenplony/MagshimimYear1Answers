def are_lists_equal(list1, list2):
	return sorted(list1) == sorted(list2)

print(are_lists_equal([1, 2, 3], [3, 2, 1]))