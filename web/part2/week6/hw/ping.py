import datetime
from scapy.all import *

PING_TIMES = 3
PING_TIMEOUT = 2
PING_RANDOM_TEXT = "I Don't Like Scapy"


def ping(target: str) -> None:
    msg = IP(dst=target) / ICMP() / PING_RANDOM_TEXT # Creating message

    strt_time = datetime.now() # Counting time
    ans = sr1(msg, verbose=0, timeout=PING_TIMEOUT) # Sending Message
    time_diff = int((datetime.now() - strt_time).total_seconds() * 1000) # Getting time difference

    avg_divide_by = PING_TIMES
    average = 0

    for i in range(PING_TIMES):
        if not (ans is None):
            print(f"succeed! {ans.src} replied! time: {time_diff}ms. ttl: {ans.ttl}") # Printing the elapsed time and stuff
            average += time_diff # adding the time difference to a sum for average
        else:
            print(f"failed. timed out.")
            avg_divide_by -= 1

    print("The average ping time is %dms" % (average / avg_divide_by))


if __name__ == "__main__":
    ping("8.8.8.8")