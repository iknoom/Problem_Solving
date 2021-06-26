MOD = 10 ** 9 + 7

dp = [0] * 2501
dp[0] = 1
for i in range(1, 2501):
    for L in range(i):
        dp[i] += dp[L] * dp[i - L - 1]
        dp[i] %= MOD

T = int(input())
for _ in range(T):
    N = int(input())
    if N & 1:
        print(0)
    else:
        print(dp[N//2])