def last_early(my_str):
	word = my_str.lower()
	return word.count(word[-1]) > 1

print(last_early("Happy birthday"))