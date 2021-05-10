from sys import stdin
input = stdin.readline
INF = float('inf')

N = int(input())
v = [int(input()) for _ in range(N)]

dp = [[-INF] * N for _ in range(N)]
dp[0][N - 1] = 0
coff = 1
for w in range(N - 1, 0, -1):
    for i in range(N):
        if i + w >= N:
            break
        dp[i][i + w - 1] = max(dp[i][i + w - 1], dp[i][i + w] + v[i + w] * coff)
        dp[i + 1][i + w] = max(dp[i + 1][i + w], dp[i][i + w] + v[i] * coff)
    coff += 1
print(max(dp[i][i] + coff * v[i] for i in range(N)))