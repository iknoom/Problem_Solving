N = int(input())
dp = [0] + [10**9] * N
for i in range(1, N+1):
    for j in range(300):
        if j*j <= i: dp[i] = min(dp[i],dp[i-j*j]+1)
print(dp[-1])