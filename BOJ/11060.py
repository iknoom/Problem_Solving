N = int(input())
A = list(map(int, input().split()))
dp = [10**9] * N
dp[0] = 0
for i in range(N):
    for j in range(1, A[i] + 1):
        if i + j < N: dp[i + j] = min(dp[i + j], dp[i] + 1)
print(dp[-1] if dp[-1] != 10**9 else -1)