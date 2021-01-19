n = int(input())

conclusions = dict()

done = False
for i in range(n):
	line = input().split()
	end = False
	for state in line:
		if (end):
			conclusions[state] = True
		elif (state == '->'):
			end = True
		elif (state not in conclusions):
			print(i + 1)
			done = True
			break
	if (done):
		break
else:
	print('correct')


