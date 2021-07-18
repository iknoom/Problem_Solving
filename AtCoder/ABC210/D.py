from sys import stdin
input = stdin.readline
INF = float('inf')

H, W, C = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
dp = [[INF] * W for _ in range(H)]

answer = INF
for y in range(H):
    for x in range(W):
        # 1
        if x > 0 and y > 0:
            dp[y][x] = min(dp[y][x], dp[y - 1][x - 1] - A[y - 1][x - 1] + A[y][x] + 2 * C)
            dp[y][x] = min(dp[y][x], A[y - 1][x - 1] + A[y][x] + 2 * C)
        # 2
        if y > 0:
            dp[y][x] = min(dp[y][x], dp[y - 1][x] - A[y - 1][x] + A[y][x] + 1 * C)
            dp[y][x] = min(dp[y][x], A[y - 1][x] + A[y][x] + 1 * C)
        # 3
        if x < W - 1 and y > 0:
            dp[y][x] = min(dp[y][x], dp[y - 1][x + 1] - A[y - 1][x + 1] + A[y][x] + 2 * C)
            dp[y][x] = min(dp[y][x], A[y - 1][x + 1] + A[y][x] + 2 * C)
        answer = min(answer, dp[y][x])

    left = [INF] * W
    for x in range(W):
        if x > 0:
            left[x] = min(left[x], left[x - 1] - A[y][x - 1] + A[y][x] + 1 * C)
            left[x] = min(left[x], A[y][x - 1] + A[y][x] + 1 * C)
    right = [INF] * W
    for x in range(W - 1, -1, -1):
        if x < W - 1:
            right[x] = min(right[x], right[x + 1] - A[y][x + 1] + A[y][x] + 1 * C)
            right[x] = min(right[x], A[y][x + 1] + A[y][x] + 1 * C)
    for x in range(W):
        dp[y][x] = min(dp[y][x], min(right[x], left[x]))
        answer = min(answer, dp[y][x])

print(answer)