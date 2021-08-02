def is_greater(my_list, n):
	new_list = []
	for i in my_list:
		if i > n:
			new_list.append(i)

	return new_list

print(is_greater([1, 30, 25, 60, 27, 28], 28))