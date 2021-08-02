from scapy.all import *

DNS_PORT = 53
DNS_SERVER = "8.8.8.8"

def nslookup(target: str) -> None:
    msg = IP(dst=DNS_SERVER) / UDP(dport=DNS_PORT) / DNS(rd=1, qd=DNSQR(qname=target))
    ans = sr1(msg, verbose=0)
    print(ans[DNSRR].rdata)

if __name__ == "__main__":
    nslookup("www.google.com")