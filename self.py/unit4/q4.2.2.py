

word = input("Enter a word: ").lower().replace(" ", "")

if (word == word[::-1]):
	print("OK")
else:
	print("NOT")