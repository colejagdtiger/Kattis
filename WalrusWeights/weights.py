
def diff(num):
	return abs(1000 - num)

n = int(input())
weights = [int(input()) for i in range(n)]

best = diff(weights[0])

sums = {weights[0] : weights[0]}

for w in weights[1:]:
	keys = list(sums.keys())
	if (w < 1000 or diff(w) < best):
		sums[w] = w
	for s in keys:
		if (s > 1000 and best < diff(s)):
			del sums[s]
		elif (diff(s + w) <= best):
			sums[s + w] = s + w
			best = diff(s + w)
		elif (s + w < 1000):
			sums[s + w] = s + w


num = 1000 + best
if num in sums:
	print(num)
else:
	print(1000 - best)


