word = input("Please enter a string: ")

first_half = word[:len(word) // 2]
second_half = word[len(word) // 2:]

first_half = first_half.lower()
second_half = second_half.upper()

print(first_half + second_half)