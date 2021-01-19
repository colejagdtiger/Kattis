L, *text = [i for i in input() if i != ' ']

out = ''
if (L == 'E'):
	count = 1
	for c in text:
		if (len(out) == 0):
			out += c
		elif (c == out[-1]):
			count += 1
		else:
			out += str(count)
			out += c
			count = 1
	out += str(count)

if (L == 'D'):
	text = text[::-1]
	while (len(text) > 0):
		c = text.pop()
		n = int(text.pop())
		out += c * n

print(out)