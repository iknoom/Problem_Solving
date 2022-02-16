INF = float('inf')

dx = [9, 9, 3, 3, 1, 1]
dy = [3, 1, 9, 1, 9, 3]
dz = [1, 3, 1, 9, 3, 9]

N = int(input())
dp = [[[INF for _ in range(61)] for _ in range(61)] for _ in range(61)]
init = list(map(int, input().split()))
while len(init) < 3:
    init.append(0)
a, b, c = init
dp[a][b][c] = 0
for x in range(60, -1, -1):
    for y in range(60, -1, -1):
        for z in range(60, -1, -1):
            for i in range(6):
                nx = max(0, x - dx[i])
                ny = max(0, y - dy[i])
                nz = max(0, z - dz[i])
                dp[nx][ny][nz] = min(dp[nx][ny][nz], dp[x][y][z] + 1)
print(dp[0][0][0])