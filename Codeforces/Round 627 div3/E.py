n, h, l, r = map(int, input().split())
A = list(map(int, input().split()))

dp = [[-1] * h for _ in range(2)]
dp[1][0] = 0
flag = 1
for i in range(n):
    for j in range(h):
        if dp[flag][j] == -1: continue
        h1 = (j + A[i]) % h
        h2 = (j + A[i] - 1) % h
        if l <= h1 <= r:
            dp[flag ^ 1][h1] = max(dp[flag ^ 1][h1], dp[flag][j] + 1)
        else:
            dp[flag ^ 1][h1] = max(dp[flag ^ 1][h1], dp[flag][j])
        if l <= h2 <= r:
            dp[flag ^ 1][h2] = max(dp[flag ^ 1][h2], dp[flag][j] + 1)
        else:
            dp[flag ^ 1][h2] = max(dp[flag ^ 1][h2], dp[flag][j])
    for j in range(h): dp[flag][j] = -1
    flag ^= 1
print(max(dp[flag]))