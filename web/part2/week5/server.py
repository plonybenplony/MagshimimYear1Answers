import socket
import data
import hashlib # Part of password extension

PORT = 4200
DEST = "127.0.0.1"
ADDR = (DEST, PORT)

WELCOME_MESSAGE = "Welcome to the PinkFloyd server!\n\nPlease enter the password"
QUIT_MESSAGE = "<\\\\\\__QUIT__///>"
WRONG_PASSWORD_MESSAGE = "WRONG_PASSWORD_SENT:(" # Part of password extension
CORRECT_PASSWORD_MESSAGE = "CORRECT_PASSWORD_SENT" # Part of password extension

SEP = "#"
MESSAGE_MAX_LENGTH = 1024

PASSWORD = "a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e" # Part of password extension


def main():
	while True:
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

		# Wait until user types the right password
		while hashlib.sha256(client_soc.recv(MESSAGE_MAX_LENGTH)).hexdigest() != PASSWORD: # Part of password extension
			print(f"[AUT] client didn't send the right password") # Part of password extension
			client_soc.sendall(WRONG_PASSWORD_MESSAGE.encode()) # Part of password extension
		client_soc.sendall(CORRECT_PASSWORD_MESSAGE.encode()) # Part of password extension

		# Mainloop
		while True:
			try:
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
			except ConnectionResetError:
				break
			except ConnectionAbortedError:
				break

		# Close the socket
		print(f"[BYE] client \"{client_address}\" has quit.")
		list_sock.close()


# Converts list to formatted string
def lts(l):
	return str(l).strip("[]").replace('\'', '')
# Converts dict keys to formatted string
def dts(l):
	return str(l).strip("dict_keys([])").replace('\'', '')


def create_msg(option, client_data):
	if option == "1": # <//__OPTION-1__\\> #
		return dts(data.get_list_of_albums()) + ' '
	elif option == "2": # <//__OPTION-2__\\> #
		return dts(data.get_songs_in_album(client_data)) + ' '
	elif option == "3": # <//__OPTION-3__\\> #
		return str(data.get_length_of_song(client_data)) + ' '
	elif option == "4": # <//__OPTION-4__\\> #
		return str(data.get_lyrics_of_song(client_data)) + ' '
	elif option == "5": # <//__OPTION-5__\\> #
		return str(data.get_album_of_song(client_data)) + ' '
	elif option == "6": # <//__OPTION-6__\\> #
		return lts(data.search_in_song_titles(client_data)) + ' '
	elif option == "7": # <//__OPTION-7__\\> #
		return lts(data.search_in_song_lyrics(client_data)) + ' '
	elif option == "8": # <//__OPTION-8__\\> #
		return QUIT_MESSAGE


if __name__ == "__main__":
	main()