N = int(input())
M = [tuple(map(int, input().split())) for _ in range(N)]

dp = [[10**9] * N for _ in range(N)]
for i in range(N): dp[i][i] = 0

for k in range(1, N):
    for i in range(N - k):
        j = i + k
        for d in range(i, j):
            dp[i][j] = min(dp[i][j], dp[i][d] + dp[d + 1][j] + M[i][0] * M[d][1] * M[j][1])

print(dp[0][-1])