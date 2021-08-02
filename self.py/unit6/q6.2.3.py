def format_list(my_list):
	return str(my_list[:-1:2]).strip("[]").replace("'", "") + ", and " + my_list[-1]

print(format_list(["hydrogen", "helium", "lithium", "beryllium", "boron", "magnesium"]))