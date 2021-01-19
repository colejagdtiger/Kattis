import math
def mod(x, y):
	return math.sqrt(x**2 + y**2)

def square(x, y):
	return [x**2 - y**2, 2*x*y]

i = 0
while 1:
	i += 1
	try:
		x, y, r = map(float, input().split())
	except:
		break
	m, n = x, y

	if (mod(m, n) > 2):
		case = 'OUT'
	for _ in range(int(r)):
		if (mod(m, n) > 2):
			case = 'OUT'
			break
		m, n = square(m, n)
		m += x
		n += y

	else:
		case = 'IN'

	print(f'Case {i}: {case}')

