def main():
	buy_list = input("Enter a list: ").split(',')

	option = 0

	while option != 9:
		option = int(input("Enter an option: "))
		if option == 1:
			opt1(buy_list)
		elif option == 2:
			opt2(buy_list)
		elif option == 3:
			opt3(buy_list)
		elif option == 4:
			opt4(buy_list)
		elif option == 5:
			opt5(buy_list)
		elif option == 6:
			opt6(buy_list)
		elif option == 7:
			opt7(buy_list)
		elif option == 8:
			opt8(buy_list)

def opt1(l):
	print(l)

def opt2(l):
	print(len(l))

def opt3(l):
	print(l.count(input("Enter an item: ")) > 0)

def opt4(l):
	print(l.count(input("Enter an item: ")))

def opt5(l):
	l.pop(l.index(input("Enter an item: ")))

def opt6(l):
	l.append(input("Enter an item: "))

def opt7(l):
	for i in l:
		if len(i) < 3 or not i.isalpha():
			print(i)

def opt8(l):
	for i in l:
		while True:
			if l.count(i) > 1:
				l.pop(l.index(i))
			else:
				break

if __name__ == "__main__":
	main()