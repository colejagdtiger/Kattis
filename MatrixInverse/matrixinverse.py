import functools
n = 0
while 1:
	n += 1
	try:
		mat = [[int(i) for i in input().split()] for _ in range(2)]
		input()
	except:
		break

	det = functools.reduce(lambda a,b: a - b, 
						   [x * y for x,y in zip(mat[0], mat[1][::-1])])
	
	switch = [[mat[1][1], mat[0][1] * -1], [mat[1][0] * -1, mat[0][0]]]
	print(f'Case {n}:')
	for x, y in switch:
		print(f'{int(x / det)} {int(y / det)}')
