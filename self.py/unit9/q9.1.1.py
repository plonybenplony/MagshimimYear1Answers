def are_files_equal(file1, file2):
	s1 = ""
	s2 = ""

	with open(file1, "r") as f1:
		s1 = f1.read()
	with open(file2, "r") as f2:
		s2 = f2.read()

	return s1 == s2

print(are_files_equal("files/1.txt", "files/3.txt"))