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
"""}

secret_word = ""
old_letters_guessed = []
num_of_tries = 0

def main():
	# Begin
	print_start_screen()

	# Get parameters
	path_to_words_file = input("Enter file path: ")
	index_of_words_in_file = int(input("Enter index: "))
	print("")

	# Globals
	global num_of_tries
	global secret_word
	global old_letters_guessed

	# Choose a word
	secret_word = choose_word(path_to_words_file, index_of_words_in_file)

	print("Let's start!")

	print(show_hidden_word(secret_word, old_letters_guessed))

	print_hangman(num_of_tries + 1)

	# Main Loop
	while True:
		get_a_guess(old_letters_guessed)
		num_of_tries += 1
		print(show_hidden_word(secret_word, old_letters_guessed))
		if check_win(secret_word, old_letters_guessed):
			print("WIN")
			break
		elif num_of_tries > MAX_TRIES:
			print("LOSE")
			break

	return None


def get_a_guess(old_letters_guessed):
	guess = ""
	while True:
		guess = input("Guess a letter: ").lower()
		if try_update_letter_guessed(guess, old_letters_guessed):
			break
	if guess not in secret_word:
		print_hangman(num_of_tries)
	old_letters_guessed += guess

def print_start_screen():
	print(HANGMAN_ASCII_ART, MAX_TRIES)

def try_update_letter_guessed(letter_guessed, old_letters_guessed):
	let = letter_guessed.lower()
	if (len(let) != 1) or (not let.isalpha()) or (let.lower() in old_letters_guessed):
		print("X")
		print(str(sorted(old_letters_guessed)).replace("[", "").replace("]", "").replace(",", " ->").replace("'", ""))
		return False

	return True

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

	return words[int(index) % len(words_with_rep) - 1]

def check_win(secret_word, old_letters_guessed):
	for i in secret_word:
		if not (i in old_letters_guessed):
			return False
	return True

def show_hidden_word(secret_word, old_letters_guessed):
	string = ""
	for i in secret_word:
		string += (i if i in old_letters_guessed else '_') + ' '
	return string[:-1]

def print_hangman(num_of_tries):
	print(HANGMAN_PHOTOS["picture %d" % num_of_tries])

if __name__ == "__main__":
	main()
