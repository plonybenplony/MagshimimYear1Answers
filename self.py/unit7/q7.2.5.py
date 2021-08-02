def sequence_del(my_str):
	new_str = ""
	for i in range(len(my_str)):
		new_str += (my_str[i] != my_str[i-1]) * my_str[i]
	return new_str

print(sequence_del("ppppyyyyyttttthhhhhhoooonnn"))