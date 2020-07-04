INF = 1e9
N = int(input())
A = list(map(int, input()))
B = list(map(int, input()))
dp = [[INF] * 10 for _ in range(N)]
ans = [[[] for _ in range(10)] for _ in range(N)]
dp[-1][A[-1]] = 0

for i in range(1, 6):
    cur = (A[-1] - i) % 10
    dp[-1][cur] = i
    ans[-1][cur].append((N, -i))
for i in range(1, 5):
    cur = (A[-1] + i) % 10
    dp[-1][cur] = i
    ans[-1][cur].append((N, i))

for i in range(N - 2, -1, -1):
    diff = B[i] - B[i + 1]
    for x in range(10):
        for y in range(10):
            dA = (x - A[i]) % 10
            dy = ((x - diff) - y) % 10

            p, q = (-dA) % 10, dy
            if dp[i][x] > dp[i + 1][y] + p + q:
                ans[i][x] = [(i + 1, -p), (i + 2, q)]
                dp[i][x] = dp[i + 1][y] + p + q

            p, q = dA, (dy - dA) % 10
            if dp[i][x] > dp[i + 1][y] + p + q:
                ans[i][x] = [(i + 1, p), (i + 2, q)]
                dp[i][x] = dp[i + 1][y] + p + q

print(dp[0][B[0]])
d = 0
for i in range(N):
    for x, y in ans[i][(B[i] - d) % 10]:
        if y: print(x, y)
        if y > 0: d += y