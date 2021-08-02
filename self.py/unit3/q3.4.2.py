word = input("Please enter a string: ")

first_char = word[0]
word = word.replace(first_char, 'e')

print(first_char + word[1:])