MOD = 10 ** 9
N = int(input())
dp = [1, 0, 1] + [-1] * N
for i in range(3, N + 1):
    dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]) % MOD
print(dp[N])