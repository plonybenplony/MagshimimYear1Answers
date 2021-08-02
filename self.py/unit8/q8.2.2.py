def my_key(tup):
	return float(tup[1])

def sort_prices(list_of_tuples):
	return sorted(list_of_tuples, key=my_key, reverse=True)

products = [('milk', '5.5'), ('candy', '2.5'), ('bread', '9.0')] 
print(sort_prices(products))