BIG_LEN = 5
SMALL_LEN = 1

def  chocolate_maker(small, big, x):
	return x % BIG_LEN <= small and x // BIG_LEN <= big

print(chocolate_maker(3, 2, 10))