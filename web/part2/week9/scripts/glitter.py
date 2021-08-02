import requests as reqs
import json
import sys
import datetime

from requests.models import Response

GLITTER_LOG_URL ="http://cyber.glitter.org.il/user"
GLITTER_LIKE_URL ="http://cyber.glitter.org.il/likes"
GLITTER_USER_ID_URL ="http://cyber.glitter.org.il/entities?searchType=WILDCARD&searchEntry="
GLITTER_PASS_RECOV_REQ ="http://cyber.glitter.org.il/password-recovery-code-request"
GLITTER_PASS_RECOV_VER ="http://cyber.glitter.org.il/password-recovery-code-verification"
GLITTER_POST_GLIT_URL ="http://cyber.glitter.org.il/glit?"
GLITTER_COMMENT_URL ="http://cyber.glitter.org.il/comments"
LOGIN_DATA = ("*****", "xgV3AMZJHkJQNus") # Changed for privacy reasons
LOGIN_HEADERS = {'Content-Type':'application/json'}
OTHER_HEADERS = {'Content-Type':'application/json',
"Accept": "application/json, text/plain, */*",
"Accept-Language": "he-IL,he;q=0.9,en-US;q=0.8,en;q=0.7",
"Cookie": "sparkle=x.x.x.x"}
COOKIE_HEADERS = {"Cookie": "sparkle=x.x.x.x"}

user_id = 0


# *--------------------------------------------------------------------------------------------------*
# Actual functions that would be called directly
# *--------------------------------------------------------------------------------------------------*

def add_likes(glit: int, amount: int) -> None:
	# Auth
	res, info = login(False)
	print("") # \n

	for i in range(amount):
		res = like(False, info, glit)
	
	logout(False, info)


def post_glit(body: str, post_as_id = 1, post_in_id = 4291, bg_color_name = "White", font_color_name = "Black", when = "2021-07-27T15:40:00.129Z") -> None:
	id = -1
	feed_owner_id = post_in_id
	publisher_id = post_as_id
	publisher_screen_name = ""
	publisher_avatar = "im1"
	background_color = bg_color_name
	date = when
	content = body
	font_color = font_color_name

	res, info = login(False)
	COOKIE_HEADERS["Cookie"] = "sparkle=" + info["sparkle"]

	URL = GLITTER_POST_GLIT_URL + f"{id=}&{feed_owner_id=}&{publisher_id=}&{publisher_screen_name=}&{publisher_avatar=}&{background_color=}&{date=}&{content=}&{font_color=}".replace("'", "")

	res = reqs.get(URL, headers=COOKIE_HEADERS)

	#print(res.status_code, " | ", res.text)

	logout(False, info)


def get_password(username: str) -> str:
	# Send to http://cyber.glitter.org.il/password-recovery-code-request the Username
	reqs.post(GLITTER_PASS_RECOV_REQ, json=username)

	# Generate code format - "{date}{id in letters (a=0)}{time}", example - "2707ECJB1031"
	date = datetime.datetime.now().strftime("%d%m")
	id_str = num_to_letters(get_id(username))
	time = datetime.datetime.now().strftime("%H%M")
	code = date + id_str + time
	if len(code) != 12: print("Error: Generated Invalid code! (I think)", code)

	# Send to http://cyber.glitter.org.il/password-recovery-code-verification array with username and code
	password = reqs.post(GLITTER_PASS_RECOV_VER, json=[username, code])

	return password.text


def comment(body: str, glit: int, when = "2000-07-27T12:38:19.394Z") -> None:
	res, info = login(False)
	COOKIE_HEADERS["Cookie"] = "sparkle=" + info["sparkle"]

	user_id = info["user"]["id"]

	data = {"content": body, "date": when, "glit_id": glit, "id": -1, "user_id": user_id, "user_screen_name": "Username"}

	res = reqs.post(GLITTER_COMMENT_URL, json=data, headers=COOKIE_HEADERS)

	print(res.status_code, " | ", res.text)

	logout(False, info)


# *--------------------------------------------------------------------------------------------------*
# Utility functions that won't be called directly
# *--------------------------------------------------------------------------------------------------*


def login(debug: bool) -> tuple:
	res = reqs.post(GLITTER_LOG_URL, json=LOGIN_DATA, auth=LOGIN_DATA, headers=LOGIN_HEADERS)
	info = json.loads(res.text)
	if debug: print(res.status_code, " | ", res.text)

	try: info["sparkle"]
	except KeyError:
		print("Error: Already logged in")
		sys.exit()
	
	OTHER_HEADERS["Cookie"] = "sparkle=" + info["sparkle"]
	user_id = info["user"]["id"]
	
	return res, info


def get_id(_username: str) -> int:
	_, log_info = login(False)

	OTHER_HEADERS["Cookie"] = "sparkle=" + log_info["sparkle"]

	res = reqs.get(GLITTER_USER_ID_URL + _username, headers=OTHER_HEADERS)
	info = json.loads(res.text)
	
	try: info[0]["id"]
	except IndexError or KeyError:
		print("Error: While getting users id, Probably because username doesn't exist")
		sys.exit()
	
	logout(False, log_info)
	
	return int(info[0]["id"])


def logout(debug: bool, _info: dict) -> Response:
	try:
		OTHER_HEADERS["Cookie"] = "sparkle=" + _info["sparkle"]
	except KeyError:
		return None

	res = reqs.delete(GLITTER_LOG_URL + "/" + str(_info["user"]["id"]), auth=LOGIN_DATA, headers=OTHER_HEADERS)
	if debug: print(res.status_code, " | ", res.text)

	return res


def create_like_data(_info: dict, _glit_id: int):
	return {"glit_id":_glit_id,"user_id":_info["user"]["id"],"user_screen_name":_info["user"]["screen_name"],"id":-1}


def like(debug: bool, _info: dict, glit_id: int):
	OTHER_HEADERS["Cookie"] = "sparkle=" + _info["sparkle"]
	_data = create_like_data(_info, glit_id)

	res = reqs.post(GLITTER_LIKE_URL, json=_data, headers=OTHER_HEADERS)
	if debug: print(res.status_code, " | ", res.text)

	return res


def unlike(debug: bool, _info: dict, like_res: reqs.Response):
	OTHER_HEADERS["Cookie"] = "sparkle=" + _info["sparkle"]

	res = reqs.delete(GLITTER_LIKE_URL + "/" + str(json.loads(like_res.text)["id"]), headers=OTHER_HEADERS)
	if debug: print(res.status_code, " | ", res.text)

	return res


def num_to_letters(num: int) -> str:
	res = ""
	for i in str(num):
		res += chr(int(i) + ord('A'))
	
	return res