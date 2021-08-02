def my_mp3_playlist(file_path):
	text = ""
	splitted = []
	grouped = []
	longest = ""
	count = 0
	freq_authour = ""

	with open(file_path, "r") as f:
		text = f.read().replace("\n", "")

	splitted = text.split(";")

	for i in range(0, len(splitted)-3, 3):
		grouped += [[splitted[i], splitted[i+1], splitted[i+2]]]

	# find longest
	max_len = 0.0
	max_index = 0
	for i in grouped:
		if float(i[2].replace(':', ".")) > max_len:
			max_len = float(i[2].replace(':', "."))
			max_index = grouped.index(i)
	longest = grouped[max_index][0]

	# find count
	count = len(grouped)

	# find most freq authour
	max_count = 0
	max_index = 0
	for i in grouped:
		if splitted.count(i[1]) > max_count:
			max_count = splitted.count(i[1])
			max_index = grouped.index(i)
	freq_authour = grouped[max_index][1]

	return longest, count, freq_authour

_ = my_mp3_playlist("files/songs.txt")
print(type(_), _)