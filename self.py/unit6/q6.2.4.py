def extend_list_x(list_x, list_y):
	new_list = list_y
	for i in list_x:
		new_list.append(i)

	return new_list

print(extend_list_x([4, 5, 6], [1, 2, 3]))