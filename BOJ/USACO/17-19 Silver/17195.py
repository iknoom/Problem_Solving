N = int(input())
A = [[1 if k == 'R' else 0 for k in input()] for _ in range(N)]
ret = []

for k in [0, -1]:
	for i in range(N):
		if A[k][i]:
			for j in range(N): A[j][i] ^= 1
	for i in range(N):
		S = sum(A[i])
		if S == 1: ret += [(i + 1, A[i].index(1) + 1)]
		elif S == N - 1: ret += [(i + 1, A[i].index(0) + 1)]
	if len(ret) == 1: break
	ret = []

if ret:
	if N == 1: print(-1)
	elif N == 2: print(1, 1)
	else: print(*ret[0])
else: print(-1)
