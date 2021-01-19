n = int(input())

trips = dict()

for _ in range(n):
	loc, time = input().split()
	time = int(time)
	if (loc in trips):
		trips[loc].append(time)
	else:
		trips[loc] = [time]

for loc in trips.keys():
	trips[loc].sort()


q = int(input())
for _ in range(q):
	loc, k = input().split()
	print(trips[loc][int(k) - 1])
