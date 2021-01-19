a, b, c, n = [int(i) for i in input().split()]

if (a > 0 and b > 0 and c > 0 and n > 2 and a + b + c >= n):
	print('YES')
else:
	print('NO')