from scapy.all import *
import json

ADDR = "34.222.145.150"
PORT = 789

day = input("Enter your birthday day: ")
month = input("Enter your birthday month: ")
text = f"Day={day},Month={month}"

message = IP(dst=ADDR) / UDP(sport=4321, dport=PORT) / Raw(load=text)

ans = sr1(message, verbose=0)
dict = json.loads(ans["Raw"].load)

data = (dict["celebs"][0]["name"].split(",")[0], 2021 - int(dict["celebs"][0]["birth-year"]), dict["celebs"][1]["name"].split(",")[0],  2021 - int(dict["celebs"][1]["birth-year"]), dict["events"][0]["year"], dict["events"][0]["text"])
# 0 = name of first celeb, 1 = age of first celeb, 2 = name of second celeb, 3 = age of second celeb, 4 = year of event, 5 = event

text = f"Hey there, you were born in {day}/{month} - it's the same birthday as {data[0]} (age {data[1]}) and {data[2]} (age {data[3]})! On your birth date in the year {data[4]} this happened: {data[5]}"

print(text)