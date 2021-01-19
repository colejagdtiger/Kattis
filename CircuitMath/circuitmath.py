n = int(input())

variables = [True if x == 'T' else False for x in input().split()]

output = []

args = input().split()

for a in args:
	if (a in ['+', '-', '*']):
		if (a == '*'):
			b = output.pop()
			c = output.pop()
			output.append(c and b)
		elif (a == '+'):
			b = output.pop()
			c = output.pop()
			output.append(c or b)
		else:
			b = output.pop()
			output.append(not b)
	else:
		output.append(variables[ord(a) - ord('A')])

print('T' if output[0] else 'F')
