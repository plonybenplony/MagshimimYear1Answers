def numbers_letters_count(my_str):
	nums_count = 0
	for i in my_str:
		nums_count += i.isdigit()
	return [nums_count, len(my_str) - nums_count]

print(numbers_letters_count("Python 3.6.3"))