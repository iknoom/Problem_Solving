dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
INF = float('inf')

N, M = map(int, input().split())
vst = [[[-1] * M for _ in range(N)] for _ in range(1 << 6)]
board = [input() for _ in range(N)]
queue = []
out = []

for i in range(N):
    for j in range(M):
        if board[i][j] == '0':
            queue.append((i, j, 0))
            vst[0][i][j] = 0
        elif board[i][j] == '1':
            out.append((i, j))

for y, x, key in queue:
    for i in range(4):
        x1, y1 = x + dx[i], y + dy[i]
        if x1 < 0 or M <= x1 or y1 < 0 or N <= y1:
            continue
        if vst[key][y1][x1] >= 0:
            continue
        if board[y1][x1] == '#':
            continue

        cur = ord(board[y1][x1])
        if ord('a') <= cur <= ord('z'):
            nxt_key = key | (1 << (cur - ord('a')))
            vst[nxt_key][y1][x1] = vst[key][y][x] + 1
            queue.append((y1, x1, nxt_key))
        elif ord('A') <= cur <= ord('Z'):
            if key & (1 << cur - ord('A')):
                vst[key][y1][x1] = vst[key][y][x] + 1
                queue.append((y1, x1, key))
        else:
            vst[key][y1][x1] = vst[key][y][x] + 1
            queue.append((y1, x1, key))

ans = INF
for i in range(1 << 6):
    for y, x in out:
        if vst[i][y][x] > 0:
            ans = min(ans, vst[i][y][x])
print(-1 if ans == INF else ans)