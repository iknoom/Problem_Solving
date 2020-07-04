N, B = map(int,input().split())
f = list(map(int,input().split()))
b = [tuple(map(int,input().split())) for _ in range(B)]
dp = [[False] * B for _ in range(N)]
dp[0][0] = True

for i in range(N):
	x = -1
	for j in range(B):
		s, d = b[j]
		if s >= f[i]:
			for k in range(1, d+1):
				if i - k >= 0 and dp[i - k][j]:
					dp[i][j] = True
					x = j
					break
		if x >= 0:
			break
	for j in range(x + 1, B):
		s, d = b[j]
		if s >= f[i]:
			dp[i][j] = True

for j in range(B):
	if dp[-1][j]:
		print(j)
		break
