import sys
input = sys.stdin.readline

N = int(input())
P = []
S = dS = 0

for _ in range(N):
	a, b = map(int,input().split())
	S += abs(a-b)
	dx = abs(a-b) - abs(a)
	if dx > 0:
		P += [(b - dx, 1), (b, -2), (b + dx, 1)]

y = t = 0
x1 = -10**8
for x2, dt in sorted(P):
	y += t * (x2 - x1)
	dS = max(dS, y)
	t += dt
	x1 = x2

print(S - dS)
