

m = int(input())

for i in range(m):
	posx, posy = map(float, input().split())
	n = int(input())
	light = False

	for _ in range(n):
		candx, candy = map(float, input().split())
		x = posx - candx
		y = posy - candy
		if ((x**2 + y**2) <= 64):
			light = True
			
	if (light):
		print('light a candle')
	else:
		print('curse the darkness')

