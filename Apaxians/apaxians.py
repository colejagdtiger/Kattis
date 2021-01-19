
out = ''
for c in input():
	if (len(out) == 0): out += c
	elif (out[-1] != c): out += c

print(out)