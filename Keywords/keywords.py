n = int(input())

keywords = set()
for _ in range(n):
	word = input()
	acc = ''
	for c in word:
		c = c.lower()
		if (c == '-'):
			c = ' '
		acc += c
	keywords.add(acc)

print(len(keywords))
