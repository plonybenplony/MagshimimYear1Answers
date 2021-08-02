import socket

PORT = 5050
DEST = "127.0.0.1"
ADDR = (DEST, PORT)

def main():
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	sock.connect(ADDR)

	msg = "NAME"
	sock.sendall( (str(msg) + str(calc_checksum(msg))).encode() )

	server_msg = sock.recv(1024).decode()

	print(server_msg)

	sock.close()

def calc_checksum(msg):
	checksum = 0
	for i in msg:
		checksum += ord(i)

	return checksum

if __name__ == "__main__":
	main()
