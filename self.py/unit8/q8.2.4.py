def sort_anagrams(strs):
	result = {}
	for i in strs:
		x = "".join(sorted(i))
		if x in result:
			result[x].append(i)
		else:
			result[x] = [i]
	return list(result.values())

print(sort_anagrams(['deltas', 'retainers', 'desalt', 'pants', 'slated', 'generating', 'ternaries', 'smelters', 'termless', 'salted', 'staled', 'greatening', 'lasted', 'resmelts']))