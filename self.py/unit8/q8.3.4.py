def inverse_dict(my_dict):
	inv_map = {}
	for k, v in my_dict.items():
		inv_map[v] = sorted(inv_map.get(v, []) + [k])
	return inv_map

print(inverse_dict({'I': 3, 'love': 3, 'self.py!': 2}))