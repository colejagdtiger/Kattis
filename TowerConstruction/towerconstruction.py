N = int(input())

towers = 0
last = 0
sequence = [int(x) for x in input().split()]
for x in sequence:
	if (x > last):
		towers += 1
	last = x

print(towers)
