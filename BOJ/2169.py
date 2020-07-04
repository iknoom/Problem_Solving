N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
dp = []
S = 0
for i in range(M):
    S += A[0][i]
    dp.append(S)

for j in range(1, N):
    L = [0] * M
    L[0] = dp[0] + A[j][0]
    for i in range(1, M):
        L[i] = A[j][i] + max(L[i - 1], dp[i])
    R = [0] * M
    R[-1] = dp[-1] + A[j][-1]
    for i in range(1, M):
        R[-i-1] = A[j][-i-1] + max(R[-i], dp[-i-1])
    for i in range(M):
        dp[i] = max(L[i], R[i])

print(dp[-1])