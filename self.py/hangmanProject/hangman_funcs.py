HANGMAN_ASCII_ART = """
  _    _                                         
 | |  | |                                        
 | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
 |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
 | |  | | (_| | | | | (_| | | | | | | (_| | | | |
 |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
					  __/ |                      
					 |___/
"""

MAX_TRIES = 6

HANGMAN_PHOTOS = {
	"picture 1":
	"""\
x-------x
""",

	"picture 2":
	"""\
x-------x
|
|
|
|
|
""",

	"picture 3":
	"""\
x-------x
|       |
|       0
|
|
|
""",

	"picture 4":
	"""\
x-------x
|       |
|       0
|       |
|
|
""",

	"picture 5":
	"""\
x-------x
|       |
|       0
|      /|\\
|
|
""",

	"picture 6":
	"""\
x-------x
|       |
|       0
|      /|\\
|      /
|
""",

	"picture 7":
	"""\
x-------x
|       |
|       0
|      /|\\
|      / \\
|
"""
}

def printStartScreen():
	print(HANGMAN_ASCII_ART, MAX_TRIES) # print the opening screen

def getNprintGuess():
	letter = input("Guess a letter: ").lower()
	print(letter)

def is_valid_input(letter_guessed):
	if len(letter_guessed) > 1:
		return False
	if not letter_guessed.isalpha():
		return False

	return True

def check_valid_input(letter_guessed, old_letters_guessed):
	if len(letter_guessed) > 1:
		return False
	if not letter_guessed.isalpha():
		return False
	if letter_guessed.lower() in old_letters_guessed:
		return False

	return True

def try_update_letter_guessed(letter_guessed, old_letters_guessed):
	let = letter_guessed.lower()
	if (len(let) > 1) or (not let.isalpha()) or (let.lower() in old_letters_guessed):
		print("X")
		print(str(sorted(old_letters_guessed)).replace("[", "").replace("]", "").replace(",", " ->").replace("'", ""))
		return False

	return True

def show_hidden_word(secret_word, old_letters_guessed):
	string = ""
	for i in secret_word:
		string += (i if i in old_letters_guessed else '_') + ' '
	return string[:-1]

def check_win(secret_word, old_letters_guessed):
	for i in secret_word:
		if not (i in old_letters_guessed):
			return False
	return True

def print_hangman(num_of_tries):
	print(HANGMAN_PHOTOS["picture %d" % num_of_tries])

def choose_word(file_path, index):
	words = []
	words_with_rep = []

	with open(file_path, "r") as f:
		words = f.read().replace("\n", " ").split(" ")
	words_with_rep = words

	res = []
	for i in words:
		if i not in res:
			res.append(i)
	words = res

	print(words)

	return len(words), words_with_rep[index % len(words_with_rep) - 1]

print(choose_word("words.txt", 15))

def getNprintNvalidateGuess():
	letter = input("Guess a letter: ").lower()

	error_index = 0

	if len(letter) > 1:
		error_index += 1
	if not letter.isalpha():
		error_index += 2

	if error_index > 0:
		print("E"+str(error_index))
	else:
		print(letter)

def getWord():
	word = input("Please enter a word: ")
	print("_ " * len(word))

