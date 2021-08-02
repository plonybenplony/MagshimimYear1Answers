def squared_numbers(start, stop):
	i = start
	nums = []
	while i <= stop:
		nums.append(i ** 2)
		i += 1
	return nums

squared_numbers(-3, 3)