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

WELCOME_MESSAGE = "Welcome to the PinkFloyd server!\n\nPlease enter the password" # Part of password extension
WRONG_PASSWORD_MESSAGE = "WRONG_PASSWORD_SENT:("  # Part of password extension

SEP = "#"
MESSAGE_MAX_LENGTH = 1024


def main():
    # Create a socket and connect to server
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(ADDR)

    while True:
        option = "9"
        data = ""

        try:
            # Receive and print the server message
            msg = sock.recv(MESSAGE_MAX_LENGTH).decode()
            print(msg)
            if msg == WELCOME_MESSAGE:  # Part of password extension
                # Part of password extension
                sock.sendall(input("Enter Password: ").encode())
                # Part of password extension
                while sock.recv(MESSAGE_MAX_LENGTH).decode() == WRONG_PASSWORD_MESSAGE:
                    # Part of password extension
                    sock.sendall(input("Enter Password: ").encode())

            # Print menu and get option
            print(MENU)
            # Option is not between 1-8
            while (not len(option) == 1) or (not ord('1') <= ord(option) <= ord('8')):
                option = input("Choose: ")

            # If option needs data- get data
            data = get_data(option)

            # Send option and data to the server
            msg = option + SEP + data
            sock.sendall(msg.encode())

            # If the user chose to quit- quit
            if option == '8':
                break
        except ConnectionResetError:
            print("[END] server was closed :(")
            break
        except ConnectionAbortedError:
            print("[END] server was closed :(")
            break

    sock.close()


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
