C, N = map(int ,input().split())
P = [tuple(map(int ,input().split())) for _ in range(N)]
dp = [float('inf')] * (C + 1000)
dp[0] = 0
for i in range(C + 1000):
    for c, p in P:
        if i - p >= 0:
            dp[i] = min(dp[i], dp[i - p] + c)
print(min(dp[C:]))