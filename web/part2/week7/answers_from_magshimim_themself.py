from scapy.all import *
from scapy.layers.dns import DNS, DNSRR
from scapy.layers.inet import TCP

HTTP_PORT = 80
WEATHER_PORT = 77
SMTP_PORT = 25
MODE_NAME = 0
FILTER_FUNC = 1
PRINT_FUNC = 2

# In web sometimes @ is encoded as %40
EMAIL_REGEX = r'[\w.-]+\%40[\w]+.\w+'


def filter_dns(pkt) -> bool:
    """
    filter DNS response packets

    param pkt: Packet from the sniffing
    type pkt: Packet
    return: true - If the packet is DNS and DNSRR
    return type: Bool
    """
    return DNS in pkt and DNSRR in pkt


def print_dns(pkt):
    """
    print IP and domain name from dns packet

    param pkt: Packet from the sniffing
    type pkt: Packet
    return: None
    return type: None
    """
    print("DNS Response for ", pkt[DNSRR].rrname, ": ", pkt[DNSRR].rdata)


def filter_http(pkt) -> bool:
    """
    filter HTTP GET packets

    param pkt: Packet from the sniffing
    type pkt: Packet
    return: If the packet is http
    """
    return Raw in pkt and TCP in pkt and pkt[TCP].dport == HTTP_PORT and "GET" in str(pkt[Raw])


def print_http(pkt):
    """
    print the HTTP GET title without `get` and without HTTP version

    param pkt: Packet from the sniffing
    type pkt: packet
    return: None
    return type: None
    """
    req = str(pkt[Raw])
    if "HTTP" in req:
        # Gets only the start of request until the HTTP/1.1 code
        http_protocol_version = req.index("HTTP")
        # Prints without the GET in the beginning
        title = req[6:http_protocol_version - 1]
        print(title)


def filter_weather(pkt) -> bool:
    """
    filter the weather server `200:ANSWER` response

    param pkt: Packet from the sniffing
    type pkt: Packet
    return: If the packet is weather and answer code is OK (200)
    """
    return TCP in pkt and pkt[TCP].sport == WEATHER_PORT and Raw in pkt and "200:ANSWER" in str(pkt[Raw])


def print_weather(pkt):
    """
    print the weather server's response

    param pkt: Packet from the sniffing
    type pkt: Packet
    """
    print(pkt[Raw])


def filter_email(pkt) -> bool:
    """
    filter smtp messages

    param pkt: Packet from the sniffing
    type pkt: Packet
    return: If the packet is SMTP (Email)
    """
    return Raw in pkt and TCP in pkt and pkt[TCP].dport == SMTP_PORT


def print_email(pkt):
    """
    print the email which in the message

    param pkt: packet from the sniffing
    type pkt: packet
    """
    data = str(pkt[Raw])
    matches = re.findall(EMAIL_REGEX, data)
    if matches is not None:
        print(matches)
        for match in matches:
            print(match)


def print_modes():
    """
    print the cod modes.
    """
    for num, mode in MODES.items():
        mode_name = mode[MODE_NAME]
        print("%d. %s" % (num, mode_name))


# Mode number : (Mode name, filter func, print func)
MODES = {
    1: ("DNS Mode", filter_dns, print_dns),
    2: ("HTTP GET Mode", filter_http, print_http),
    3: ("Weather Mode", filter_weather, print_weather),
    4: ("Email Scanner", filter_email, print_email)
}


def main():
    while True:
        print_modes()
        user_choice = input("Enter your choice: ")
        if not user_choice.isdigit() or int(user_choice) not in MODES.keys():
            print("Wrong choice.")
            continue
        try:
            sniff(lfilter=MODES[int(user_choice)][FILTER_FUNC], prn=MODES[int(user_choice)][PRINT_FUNC])
        except KeyboardInterrupt:
            print("User stopped sniffing")


if __name__ == "__main__":
    main()