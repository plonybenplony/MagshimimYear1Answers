def who_is_missing(file_name):
	NEW_FILE = "found.txt"

	content = []
	with open(file_name, "r") as f:
		content = sorted(f.read().split(","))
	print(content)

	for i in range(len(content)):
		if int(content[i]) != i+1:
			break

	with open(NEW_FILE, "w") as nf:
		nf.write(str(i+1))

	return i+1

print(who_is_missing("files/find_me.txt"))