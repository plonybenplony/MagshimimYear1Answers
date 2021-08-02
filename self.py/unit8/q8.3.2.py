person = {'first_name': 'Mariah', 'last_name': 'Carey', 'birth_date': '27.03.1970', 'hobbies': ['Sing', 'Compose', 'Act']}

def main():
	action = int(input("Enter a number (1-7): "))
	if action == 1:
		print(person['last_name'])
	elif action == 2:
		print(person['birth_date'].split('.')[1])
	elif action == 3:
		print(len(person['hobbies']))
	elif action == 4:
		print(person['hobbies'][-1])
	elif action == 5:
		person['hobbies'] += 'Cooking'
	elif action == 6:
		print(tuple(person['birth_date'].split('.')))
	elif action == 7:
		person['age'] = 2020 - int(person['birth_date'].split('.')[2])
		print(person['age'])


if __name__ == "__main__":
	main()