import datetime
from scapy.all import *

DNS_PORT = 53
DNS_SERVER = "8.8.8.8"

PING_TIMES = 3
PING_TIMEOUT = 2
PING_RANDOM_TEXT = "I Don't Like Scapy"

CMD_START_LINE = "CMD > "
CMD_EXIT_CMD = "exit"
CMD_NSLOOKUP_CMD = "nslookup"
CMD_PING_CMD = "ping"
CMD_TRACERT_CMD = "tracert"

def main():
    inp = input("> ")
    while inp.lower() != CMD_EXIT_CMD:
        if inp.lower().split(" ")[0] == CMD_NSLOOKUP_CMD:
            nslookup(inp.split(" ")[1])
        elif inp.lower().split(" ")[0] == CMD_PING_CMD:
            ping(inp.split(" ")[1])
        elif inp.lower().split(" ")[0] == CMD_TRACERT_CMD:
            tracert(inp.split(" ")[1])
        else:
            print("Unknown Command")
        inp = input("> ")


def nslookup(target: str) -> None:
    msg = IP(dst=DNS_SERVER) / UDP(dport=DNS_PORT) / DNS(rd=1, qd=DNSQR(qname=target))
    ans = sr1(msg, verbose=0)
    print(ans[DNSRR].rdata)


def just_ping(target: str, _timeout: float = PING_TIMEOUT, _ttl: int = 64) -> Tuple:
    msg = IP(dst=target, ttl=_ttl) / ICMP() / PING_RANDOM_TEXT # Creating message

    strt_time = datetime.now() # Counting time
    ans = sr1(msg, verbose=0, timeout=_timeout) # Sending Message
    time_diff = int((datetime.now() - strt_time).total_seconds() * 1000) # Getting time difference

    if ans is None:
        return False, None
    else:
        return True, time_diff, ans.ttl, ans.src, ans.type


def ping(target: str) -> None:
    avg_divide_by = PING_TIMES
    average = 0
    for i in range(PING_TIMES):
        rep = just_ping(target)
        if rep[0]:
            print(f"succeed! {rep[3]} replied! time: {rep[1]}ms. ttl: {rep[2]}") # Printing the elapsed time and stuff
            average += rep[1] # adding the time difference to a sum for average
        else:
            print(f"failed. timed out.")
            avg_divide_by -= 1

    print("The average ping time is %dms" % (average / avg_divide_by))


def tracert(target: str) -> None:
    i = 0
    rep = just_ping(target, PING_TIMEOUT, i)
    while rep[4] != 0:
        i += 1
        rep = just_ping(target, PING_TIMEOUT, i)
        print(f"{i}: {rep[3]}")
    

if __name__ == "__main__":
    main()