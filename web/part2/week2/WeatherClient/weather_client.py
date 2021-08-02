import socket
import math
import datetime

PORT = 77
DEST = "34.218.16.79"
ADDR = (DEST, PORT)

def get_weather(city, date):
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect(ADDR)

	server_msg = sock.recv(64).decode()

	citysum = sum([ord(c) - ord('`') for c in city.lower()])
	datesum = sum([int(c) for c in date.replace("/", "")])

	msg = f"100:REQUEST:city={city}&date={date}&checksum={citysum}.{datesum}" #"100:REQUEST:city=Eilat&date=24/04/2019&checksum=47.22"
	sock.sendall( msg.encode() )

	server_msg = sock.recv(1024).decode()

	sock.close()

	if not server_msg.startswith("200"):
		return 999, server_msg.split(":")[-2] + ":" + server_msg.split(":")[-1][:-1]
	else:
		return float(server_msg.split("&")[-2].split("=")[-1]), server_msg.split("&")[-1].split("=")[-1]


def main():
	chosen_city = input("What city do you want to know the weather of? ")

	if input("Enter 1 to get today's weather. Enter 2 to get the weather for the next three days: ") == "1":
		print(get_weather(chosen_city, datetime.date.today().strftime("%d/%m/%Y")))
	else:
		for i in range(4):
			dd = int(datetime.date.today().strftime("%d")) + i
			d = f"{dd:02d}" + datetime.date.today().strftime("/%m/%Y")
			t = get_weather(chosen_city, d)
			print(f"{d}, Temperature: {t[0]}, {t[1]}")


if __name__ == "__main__":
	main()