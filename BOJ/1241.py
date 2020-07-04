import sys
input = sys.stdin.readline
MAX = 1000000
N = int(input())
Q = sorted((int(input()), i) for i in range(N))
C = [0] * (MAX + 1)
t = 0
for i in range(N):
	if i != N - 1 and Q[i][0] == Q[i + 1][0]:
		C[Q[i][0]] += 1
		t += 1
		continue
	a = 2
	while Q[i][0] * a <= MAX:
		C[Q[i][0] * a] += 1 + t
		a += 1
	t = 0
ans = [0] * N
for a, b in Q:
	ans[b] = C[a]
print(*ans, sep='\n')
