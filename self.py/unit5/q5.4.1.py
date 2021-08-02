import math

def func(num1, num2):
	"""Calculates the vector's magnitude and angle (in celsius) with the given numbers.
	:param num1: vector's x value
	:param num2: vector's y value
	:type num1: float
	:type num2: float
	:return: The magnitude and the angle of the given vector
	:rtype: float, int
	"""
	mag = math.sqrt(num1*num1 + num2*num2)
	angle = int(math.atan2(num1, num2) * 180 / math.pi)

	return mag, angle

def main():
	# call the function func
	help(func)

if __name__ == "__main__":
	main()