import sys
INF = sys.maxsize
N, B = map(int, input().split())
A = list(map(int, input().split()))
C = list(map(int, input().split()))

dp = [-1] * 10002
tmp = [-1] * 10002
dp[0] = 0

for k in range(N):
    for i in range(10002):
        j = i - C[k]
        if j >= 0 and dp[j] != -1:
            tmp[i] = max(dp[i], dp[j] + A[k])
    for i in range(10002):
        if tmp[i] >= 0:
            dp[i] = tmp[i]
            tmp[i] = -1

ans = -1

for i in range(10002):
    if dp[i] >= B:
        ans = i
        break
print(ans)