def mult_tuple(tuple1, tuple2):
	tups_list = []
	for i in range(len(tuple1)):
		for j in range(len(tuple2)):
			tups_list += [(tuple1[i], tuple2[j])]
			tups_list += [(tuple2[j], tuple1[i])]

	return tuple(tups_list)

print(mult_tuple((1, 2), (4, 5)))