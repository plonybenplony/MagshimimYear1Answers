def fix_age(age):
	if age >= 13 and age <= 19 and (age != 16 and age != 15):
		return 0
	return age

def filter_teens(a=13 ,b=13, c=13):
	f_a = fix_age(a)
	f_b = fix_age(b)
	f_c = fix_age(c)

	return f_a + f_b + f_c