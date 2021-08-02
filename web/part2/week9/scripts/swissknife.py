import datetime
import glitter
import requests as reqs
import json

MENU = "What would you like to do?\n\
 [1] Add likes to a glit\n\
 [2] Post an illegal glit\n\
 [3] Comment on a glit (can be illegal)\n\
 [4] Get someone's password by he's username\n\
 [5] Exit\n"

def main() -> None:
	opt = 0

	# Login
	print("Welcome to My (uncompleted) swissknife!")
	print("Please login-")
	username = input("username: ")
	password = input("password: ")
	res = reqs.post(glitter.GLITTER_LOG_URL, json=[username, password], headers=glitter.LOGIN_HEADERS)
	while res.status_code != 200:
		glitter.logout(False, json.loads(res.text))
		res = reqs.post(glitter.GLITTER_LOG_URL, json=[username, password], headers=glitter.LOGIN_HEADERS)
		print("Username or password aren't correct, retry")
		username = input("username: ")
		password = input("password: ")
	glitter.LOGIN_DATA = (username, password)
	glitter.logout(False, json.loads(res.text))

	# Mainloop
	while True:
		opt = intput(MENU)
		if opt == 1:
			option1()
		elif opt == 2:
			option2()
		elif opt == 3:
			option3()
		elif opt == 4:
			option4()
		elif opt == 5:
			break
		else:
			print(f"{opt} is an invalid option")
	
	print("Bye!")


# *--------------------------------------------------------------------------------------------------*
# Options:
# *--------------------------------------------------------------------------------------------------*

def option1():
	addto = intput("To which glit? (example- 28238): ", 1, float('inf'))
	amount = intput("How many likes: ", 0, float('inf'))
	glitter.add_likes(addto, amount)


def option2():
	text = input("What should be written inside: ")
	feedid = 1 # TODO: change to user's id
	publisherid = 1 # TODO: change to user's id
	bgcolor = "White"
	fontcolor = "Black"
	time = datetime.datetime.now()
	if input("Do you want to change the feed id and the publisher's id? (y/n)") == 'y':
		feedid = intput("Enter the user id to post glit in (example- 4291): ", 1, float('inf'))
		publisherid = intput("Enter the user id of the user to post (example- 4291): ", 1, float('inf'))
	if input("Do you want to change the colors? (y/n)") == 'y':
		bgcolor = input("Choose a background color (example- White, make sure it's a real color): ")
		bgcolor = input("Choose a font color (example- Black, make sure it's a real color): ")
	time = change_time()
	
	when = time.strftime("%Y-%m-%dT%H:%M:%S.000Z")
	glitter.post_glit(text, publisherid, feedid, bgcolor, fontcolor, when)


def option3():
	text = input("What should be written inside: ")
	glit = intput("To which glit? (example- 28238): ", 1, float('inf'))
	time = change_time().strftime("%Y-%m-%dT%H:%M:%S.000Z")

	glitter.comment(text, glit, time)


def option4():
	username = input("Enter a username to find it's password: ")
	print(glitter.get_password(username))

# *--------------------------------------------------------------------------------------------------*
# Utilities:
# *--------------------------------------------------------------------------------------------------*


def change_time() -> datetime.datetime:
	if input("Do you want to change the time? (y/n)") == 'y':
		y = intput("Choose a year (example- 2020): ", 1, 2021)
		m = intput("Choose a month (example- 7): ", 1, 12)
		d = intput("Choose a day in a month (example- 17, make sure it's real): ", 1, 31) 
		h = intput("Choose the hour (example- 19): ", 0, 23)
		min = intput("Choose the mintue (example- 40): ", 0, 59)
		return datetime.datetime(y, m, d, h, min, 0, 0)
	return datetime.datetime.now()


def intput(msg: str, min=1, max=5) -> int:
	def int_fit(opt: str) -> bool:
		try:x = int(opt)
		except ValueError:return False
		if x < min or x > max:return False
		return True
	
	x = input(msg)
	while not int_fit(x):
		x = input(f"Invalid Input! Only numbers between {min}-{max}")
	
	return int(x)


if __name__ == "__main__":
	main()