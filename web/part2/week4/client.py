import socket

PORT = 4200
DEST = "127.0.0.1"
ADDR = (DEST, PORT)

MENU = """
Choose an option from the list:
	1 - get a list of all albums
	2 - get a list of all songs in chosen album
	3 - get the length of chosen song
	4 - get the lyrics of chosen song
	5 - get the album of a chosen song
	6 - search song name with chosen phrase
	7 - search song lyrics with chosen phrase
	8 - Quit\
"""

SEP = "#"
MESSAGE_MAX_LENGTH = 1024


def main():
	# Create a socket and connect to server
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect(ADDR)

	while True:
		option = "9"
		data = ""

		# Recieve and print the server message 
		recieve(sock)

		# Print menu and get option
		print(MENU)
		while not (ord('1') <= ord(option) <= ord('8')): # Option is not between 1-8
			option = input()

		# If option needs data- get data
		data = get_data(option)

		# Send option and data to the server
		msg = option + SEP + data
		sock.sendall(msg.encode())

		# If the user chose to quit- quit
		if option == '8':
			break

	sock.close()


def recieve(sock_):
	print(sock_.recv(MESSAGE_MAX_LENGTH).decode())


def get_data(opt):
	if opt == "1":
		return ""
	elif opt == "2":
		return input("Enter a album name: ")
	elif opt == "3":
		return input("Enter a song name: ")
	elif opt == "4":
		return input("Enter a song name: ")
	elif opt == "5":
		return input("Enter a song name: ")
	elif opt == "6":
		return input("Enter a phrase to search: ")
	elif opt == "7":
		return input("Enter a phrase to search: ")
	else:
		return ""


if __name__ == "__main__":
	main()