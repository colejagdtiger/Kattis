t = int(input())

for _ in range(t):
	n = int(input())
	poly1 = {j : int(i) for i, j in zip(input().split(), range(n + 1))}
	m = int(input())
	poly2 = {j : int(i) for i, j in zip(input().split(), range(m + 1))}

	prod = []

	for i in range(n + m + 1):
		ind1 = min(i, n)
		ind2 = i - ind1
		coeff = 0
		while (ind1 >= 0 and ind2 <= m):
			coeff += poly1[ind1] * poly2[ind2]
			ind1 -= 1
			ind2 += 1
		prod.append(str(coeff))

	print(n + m)
	print(' '.join(prod))