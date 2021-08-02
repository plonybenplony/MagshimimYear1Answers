import datetime
from scapy.all import *

PING_TIMES = 3
PING_TIMEOUT = 2
PING_RANDOM_TEXT = "I Don't Like Scapy"


def just_ping(target: str, _timeout: float = PING_TIMEOUT, _ttl: int = 64) -> Tuple:
    msg = IP(dst=target, ttl=_ttl) / ICMP() / PING_RANDOM_TEXT # Creating message

    strt_time = datetime.now() # Counting time
    ans = sr1(msg, verbose=0, timeout=_timeout) # Sending Message
    time_diff = int((datetime.now() - strt_time).total_seconds() * 1000) # Getting time difference

    if ans is None:
        return False, None, None, None, None
    else:
        return True, time_diff, ans.ttl, ans.src, ans.type


def tracert(target: str) -> None:
    i = 0
    rep = just_ping(target, PING_TIMEOUT, i)
    while rep[4] != 0:
        i += 1
        rep = just_ping(target, PING_TIMEOUT, i)
        if rep[0]:
            print(f"{i}: {rep[3]}")
        else:
            print(f"{i}: failed.")


if __name__ == "__main__":
    tracert("www.google.com")