N = int(input())
A = list(map(int, input().split()))
dp = [0] * (N + 1)
for i in range(N):
    min_v = A[i]
    max_v = A[i]
    for j in range(i, -1, -1):
        min_v = min(min_v, A[j])
        max_v = max(max_v, A[j])
        dp[i + 1] = max(dp[i + 1], dp[j] + max_v - min_v)
print(dp[-1])