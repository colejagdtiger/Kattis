

while 1:
	n = int(input())
	if (n == 0):
		break
	names = [input() for _ in range(n)]
	names.sort(key=lambda name: name[:2])

	for name in names:
		print(name)
	print()