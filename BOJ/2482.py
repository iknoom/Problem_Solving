MOD = 10 ** 9 + 3

def solve(n, k):
    if k == 0:
        return 1
    dp = [[0] * (k + 1) for _ in range(n)]
    dp[0][1] = 1
    for i in range(n):
        dp[i][1] = 1
        if i > 0:
            for j in range(k + 1):
                dp[i][j] += dp[i - 1][j]
        if i > 1:
            for j in range(1, k):
                dp[i][j + 1] += dp[i - 2][j]
                dp[i][j + 1] %= MOD
    return dp[-1][k]

N = int(input())
K = int(input())
answer = (solve(N - 3, K - 1) * 2 + solve(N - 2, K)) % MOD
print(answer)