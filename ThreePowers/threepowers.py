import math

n = int(input())

while (n != 0):

	sequence = list()

	while (n > 1):
		b = math.floor(math.log(n) / math.log(2))
	
		if (n == 2**b):
			n -= 2**(b-1)
			b -= 1
		else:
			n -= 2**b
		sequence.append(' ' +str(3**b))

	print('{' + ','.join(sequence[::-1]), '}')
	n = int(input())