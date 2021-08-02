def arrow(my_char, max_length):
	string = ""
	for i in range(max_length * 2):
		for j in range(i if i <= 5 else max_length - (i - 5)):
			string += my_char
		string += '\n'
	return string[1:-1]

print(arrow('*', 5))