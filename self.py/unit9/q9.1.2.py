SORT_WORD = "sort"
REV_WORD = "rev"
LAST_WORD = "last"

def main():
	path = input("Enter a file path: ")
	task = input("Enter a task: ")
	lines = []
	string = ""

	with open(path, "r") as f:
		content = f.readlines()
	string = "".join(content).replace("\n", " ")

	if task == SORT_WORD:
		print(sorted(list(set(string.split(' ')))))
	elif task == REV_WORD:
		for i in content:
			print(i[::-1])
	elif task == LAST_WORD:
		num = int(input("Enter a number: "))
		print("".join(content[-num:]))

if __name__ == "__main__":
	main()