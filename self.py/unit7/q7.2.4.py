def seven_boom(end_number):
	result = []
	for i in range(end_number+1):
		result.append('BOOM' if (i % 7 == 0 or '7' in str(i)) else i)
	return result

print(seven_boom(7))