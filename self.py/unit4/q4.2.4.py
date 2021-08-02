import calendar

date = input("Enter a date: ")

d = int(date[:2])
m = int(date[3:5])
y = int(date[6:])

day = calendar.weekday(y, m, d)

if day == 0:
	print("Monday")
elif day == 1:
	print("Tuesday")
elif day == 2:
	print("Wednesday")
elif day == 3:
	print("Thursday")
elif day == 4:
	print("Friday")
elif day == 5:
	print("Saturday")
elif day == 6:
	print("Sunday")