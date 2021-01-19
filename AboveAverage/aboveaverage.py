C = int(input())

for _ in range(C):
	N, *grades = [int(i) for i in input().split()]
	avg = sum(grades) / N
	count = 0
	for grade in grades:
		if (grade > avg):
			count += 1

	print('{:.3f}%'.format(count/N * 100))