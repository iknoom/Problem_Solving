g = [[0] * 2001 for _ in range(2001)]

def fill(x1, y1, x2, y2, t):
	for y in range(y1, y2):
		for x in range(x1, x2):
			g[y + 1000][x + 1000] = t

for t in [1, 0]:
	x1, y1, x2, y2 = map(int, input().split())
	fill(x1, y1, x2, y2, t)

a = c = 1e9
b = d = -1e9
for i in range(2001):
	for j in range(2001):
		if g[i][j]:
			a, b = min(a, i), max(b, i)
			c, d = min(c, j), max(d, j)

ans = (b - a + 1) * (d - c + 1)
if abs(ans) > 1e8:
	print(0)
else:
	print(ans)
