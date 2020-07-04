N, S, M = map(int,input().split())
P = list(map(int,input().split()))

dp = [[False]*(M+1) for _ in range(N+1)]
dp[0][S] = True
for i in range(1,N+1):
	for j in range(M+1):
		if dp[i-1][j]:
			for k in [P[i-1], -P[i-1]]:
				if 0 <= j+k <= M:
					dp[i][j+k] = True

for i in range(M+1):
	if dp[-1][M-i]:
		print(M-i)
		exit()
print(-1)
