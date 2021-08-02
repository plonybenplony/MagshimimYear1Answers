def longest(my_list):
	return sorted(my_list, key=len)[-1]

print(longest(["my_list", "hhhhhhhhhh", "a", "b"]))