def copy_file_content(source, destination):
	text = ""
	with open(source, "r") as src:
		text = src.read()
	with open(destination, "w") as dst:
		dst.write(text)

copy_file_content("files/copy.txt", "files/paste.txt")