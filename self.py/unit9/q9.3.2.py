def listfy_file(file):
	text = ""
	splitted = []
	grouped = []
	with open(file, "r") as f:
		text = f.read().replace("\n", "")
	splitted = text.split(";")
	for i in range(0, len(splitted)-3, 3):
		grouped += [[splitted[i], splitted[i+1], splitted[i+2]]]
	return grouped

def stringfy_list(l):
	text = ""
	for i in l:
		if len(str(i[0])) > 0 and len(str(i[1])) > 0:
			text += str(i[0]) + ";" + str(i[1]) + ";" + str(i[2]) + ";\n"
		elif len(str(i[0])) > 0 and not len(str(i[1])) > 0:
			text += str(i[0]) + ";"
		else:
			text += "\n"

	return text

def my_mp4_playlist(file_path, new_song):
	content = listfy_file(file_path)

	while len(content) < 3:
		content += [["", "", ""]]

	content[2][0] = new_song

	with open(file_path, "w") as f:
		f.write(stringfy_list(content))

	print(stringfy_list(content))

print(my_mp4_playlist("files/songs.txt", "different name"))