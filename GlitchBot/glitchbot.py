import copy
x, y =[int(i) for i in input().split()]
n = int(input())

def simulate(test):
	dir_x = 0
	dir_y = 1
	pos_x = 0
	pos_y = 0
	for move in test:
		if (move == 'Forward'):
			pos_x += dir_x
			pos_y += dir_y
		else:
			d = 0
			if (move == 'Right'): d = 1
			elif (move == 'Left'): d = -1
			if (abs(dir_x) == 1): dir_x, dir_y = 0, d * dir_x * -1
			elif (abs(dir_y) == 1): dir_x, dir_y = d * dir_y, 0
	
	if (pos_x == x and pos_y == y):
		return True
	return False


moves = [input() for _ in range(n)]
find = False
for i in range(len(moves)):
	test = copy.deepcopy(moves)
	for move in ['Right', 'Left', 'Forward']:
		if (move == moves[i]):
			continue
		test[i] = move
		if (simulate(test)):
			find = True
			break
	if (find):
		break

print(i + 1, move)