import socket

PORT = 4200
DEST = "127.0.0.1"
ADDR = (DEST, PORT)

WELCOME_MESSAGE = "Welcome to the PinkFloyd server!"
QUIT_MESSAGE = "<\\\\\\__QUIT__///>"

SEP = "#"
MESSAGE_MAX_LENGTH = 1024


def main():
	# Creating a socket and binding it
	list_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	list_sock.bind(ADDR)
	print(f"[ACK] Binded {ADDR} to self.")

	# Connect client
	list_sock.listen(1)
	client_soc, client_address = list_sock.accept()
	print(f"[NEW] New client has connected: {client_address}.")

	# Send welcome message
	print(f"[WEL] Sending to \"{client_address}\" the message \"{WELCOME_MESSAGE}\".")
	client_soc.sendall(WELCOME_MESSAGE.encode())

	# Mainloop
	while True:
		# Get client's message and parse it
		client_msg = client_soc.recv(MESSAGE_MAX_LENGTH).decode()
		print(f"[MSG] Client {client_address} has sent \"{client_msg}\"")
		opt_data = client_msg.split(SEP)

		# Creating and sending the correct message
		msg = create_msg(opt_data[0], opt_data[1].lower() if len(opt_data) > 1 else "")
		if msg == QUIT_MESSAGE:
			break

		# Sending the message to the client
		print(f"[ANS] Sending to \"{client_address}\" the message \"{msg}\".")
		client_soc.sendall(msg.encode())

	# Close the socket
	print(f"[END] Closing the loop.")
	list_sock.close()


def create_msg(option, data):
	if option == "1": # <//__OPTION-1__\\> #
		return "[ALBUM-LIST]"
	elif option == "2": # <//__OPTION-2__\\> #
		return f"the song list of album '{data}' is [SONG-LIST]"
	elif option == "3": # <//__OPTION-3__\\> #
		return f"the length of the song '{data}' is [LENGTH]"
	elif option == "4": # <//__OPTION-4__\\> #
		return f"the words of the song '{data}' are: [WORDS]"
	elif option == "5": # <//__OPTION-5__\\> #
		return f"the song '{data}' is in album- [ALBUM]"
	elif option == "6": # <//__OPTION-6__\\> #
		return f"the song titles that contain the phrase '{data}' are [SONG-LIST]"
	elif option == "7": # <//__OPTION-7__\\> #
		return f"the songs that contain the phrase '{data}' are [SONG-LIST]"
	elif option == "8": # <//__OPTION-8__\\> #
		return QUIT_MESSAGE


if __name__ == "__main__":
	main()