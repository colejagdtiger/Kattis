S, C, K = [int(i) for i in input().split()]

socks = sorted([int(i) for i in input().split()])

n = 0

while (len(socks) != 0):
	num = 0
	m = socks[-1] - K
	n += 1
	while (m <= socks[-1] and num < C):
		socks.pop()
		num += 1
		if (len(socks) == 0):
			break

print(n)

