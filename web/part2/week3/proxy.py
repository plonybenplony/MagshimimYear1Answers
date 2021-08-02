import socket
import datetime

MAX_GENRE_LEN = 20

LIST_PORT = 9090
SERVER_PORT = 92

LIST_ADDRESS = "127.0.0.1"
SERVER_ADDRESS = "54.71.128.194"


def main():
    list_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    list_sock.bind((LIST_ADDRESS, LIST_PORT))

    current_year = datetime.date.today().year

    while True:
        # Connect to the app
        list_sock.listen(1)
        client_soc, client_address = list_sock.accept()
        print(f"[NEW] New client has connected: {client_address}.")

        # Connect to the server
        server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_sock.connect((SERVER_ADDRESS, SERVER_PORT))

        # Receive the message from the app, Fix it and send it to the server
        client_msg = client_soc.recv(1024).decode()
        print(f"[MSG] Client {client_address} has sent \"{client_msg}\" passing message to server")
        if client_msg.split("&")[-1].split(":")[-1] == "France":
            client_soc.sendall(b"ERROR#\"France is banned!\"")
            continue
        elif int(client_msg.split("&")[1].split(":")[-1].split("-")[0]) > current_year or int(client_msg.split("&")[1].split(":")[-1].split("-")[-1]) > current_year:
            client_soc.sendall(b"ERROR#\"One or more of the year fields are in the future\"")
            continue
        elif len(client_msg.split("&")[0].split("#")[-1].split(":")[-1]) > MAX_GENRE_LEN:
            client_soc.sendall(b"ERROR#\"The genre field is too long\"")
            continue
        server_sock.sendall(client_msg.encode())

        # Receive the message from the server, Fix it and send it to the app
        server_msg = ""
        while server_msg == "":
            server_msg = server_sock.recv(1024).decode()
        print(f"[MSG] Server has sent \"{server_msg}\" Fixing it and passing it")
        if "SERVERERROR" in server_msg:
            server_msg_list = server_msg.split("#")
            server_msg_list[0] = "ERROR"
            server_msg = "#".join(server_msg_list)
        elif "imageurl" in server_msg:
            fixed_url = server_msg.split("&")[-2][:-4] + "." + server_msg.split("&")[-2][-4:]
            server_msg_list = server_msg.split("&")
            server_msg_list[-2] = fixed_url
            server_msg = "&".join(server_msg_list)
        client_soc.sendall(server_msg.encode())

        server_sock.close()

    print(f"[END] Closing the loop.")
    list_sock.close()


if __name__ == "__main__":
    main()
