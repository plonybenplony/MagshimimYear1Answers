def count_chars(my_str):
	appearances = {}

	for i in my_str:
		if my_str.count(i) > 0 and i.isalpha():
			appearances[i] = my_str.count(i)

	return appearances

print(count_chars("abra cadabra"))