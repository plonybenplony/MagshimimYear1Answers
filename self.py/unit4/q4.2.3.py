inp = input("Insert the temperature you would like to convert: ").lower()
celsius = inp.endswith("c")
temp = float(inp[:-1])

if celsius:
	print(str(((temp * 9) + (32 * 5)) / 5) + "F")
else:
	print(str(((temp * 5) - (160)) / 9) + "C")