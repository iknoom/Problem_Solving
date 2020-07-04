N = int(input())
dp = [0] * (N + 9)
dp[3] = 0
dp[4] = 1
for i in range(5, N+1):
    dp[i] = dp[(i+1) >> 1] + 2
print(dp[N])