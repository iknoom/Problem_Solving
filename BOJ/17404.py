import sys
INF = sys.maxsize
N = int(input())

COST = [tuple(map(int,input().split())) for _ in range(N)]

ans = INF

for i in range(3):
    dp = [[INF] * 3 for _ in range(N)]
    dp[0][i] = COST[0][i]
    for j in range(1, N):
        for k in range(3):
            x, y = (k + 1) % 3, (k + 2) % 3
            dp[j][k] = min(dp[j - 1][x], dp[j - 1][y]) + COST[j][k]
    x, y = (i + 1) % 3, (i + 2) % 3
    ans = min(ans, min(dp[-1][x], dp[-1][y]))

print(ans)