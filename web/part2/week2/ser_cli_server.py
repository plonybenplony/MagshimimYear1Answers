import socket
import datetime
import random

PORT = 5050
DEST = "127.0.0.1"
ADDR = (DEST, PORT)

TIME_MSG = "TIME"
NAME_MSG = "NAME"
RAND_MSG = "RAND"
QUIT_MSG = "QUIT"

MSG_LEN = 4
CHECKSUM_LEN = 3


def main():
	list_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	list_sock.bind(ADDR)

	print(f"[ACK] Binded {ADDR} to self.")

	while True:
		list_sock.listen(1)

		client_soc, client_address = list_sock.accept()
		print(f"[NEW] New client has connected: {client_address}.")

		client_msg = client_soc.recv(MSG_LEN+CHECKSUM_LEN).decode()
		print(f"[MSG] Client {client_address} has sent \"{client_msg}\" which is \"{client_msg[:4]}\" with {client_msg[4:]} as checksum")

		msg = ""
		if calc_checksum(client_msg[:4]) == int(client_msg[4:]):
			client_msg = client_msg[:4]
			if client_msg == QUIT_MSG:
				break
			elif client_msg == TIME_MSG:
				msg = datetime.datetime.now().strftime("%H:%M:%S")
			elif client_msg == NAME_MSG:
				msg = "The name is ser(sir), ser-ver."
			elif client_msg == RAND_MSG:
				msg = str(random.randrange(1, 10))
		else:
			msg = "Bad Checksum"

		print(f"[REP] Sending to Client \"{client_address}\" the message {msg}.")

		client_soc.sendall(msg.encode())

	print(f"[END] Closing the loop.")

	list_sock.close()


def calc_checksum(msg):
	checksum = 0
	for i in msg:
		checksum += ord(i)

	return checksum


if __name__ == "__main__":
	main()
