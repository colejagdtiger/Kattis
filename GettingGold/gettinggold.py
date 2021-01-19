import sys

sys.setrecursionlimit(10000000)

def update(i, j):
	if (board[i][j] == 'G'):
		global gold
		gold += 1

	board[i][j] = 'P'

	checks = set()
	for x in range(-1, 2):
		x += i
		if (board[x][j] == 'T'):
			return
		checks.add((x, j))
	for y in range(-1, 2):
		y += j
		if (board[i][y] == 'T'):
			return
		checks.add((i, y))

	for x, y in checks:
		if (board[x][y] == 'G' or board[x][y] == '.'):
			update(x, y)


W, H = [int(i) for i in input().split()]

board = [list(input()) for _ in range(H)]


gold = 0

for i in range(H):
	for j in range(W):
		if (board[i][j] == 'P'):
			update(i, j)

print(gold)
