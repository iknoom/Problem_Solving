dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

row_sum = []
for r in range(N):
    prefix = [0]
    for c in range(M):
        prefix.append(board[r][c] + prefix[-1])
    row_sum.append(prefix)
print()
for row in row_sum:
    print(row)
print()
col_sum = []
for c in range(M):
    prefix = [0]
    for r in range(N):
        prefix.append(board[r][c] + prefix[-1])
    col_sum.append(prefix)

for row in col_sum:
    print(row)

H, W, Sr, Sc, Fr, Fc = map(int, input().split())
Sr -= 1; Sc -= 1; Fr -= 1; Fc -= 1

visited = [[-1] * M for _ in range(N)]
visited[Sr][Sc] = 0
queue = [(Sr, Sc)]
for r, c in queue:
    for i in range(4):
        nr, nc = r + dy[i], c + dx[i]
        if nr < 0 or nr + H - 1 >= N:
            continue
        if nc < 0 or nc + W - 1 >= M:
            continue
        if visited[nr][nc] >= 0:
            continue
        if row_sum[nr][nc + W] - row_sum[nr][nc]: # O(1)
            continue
        if col_sum[nc][nr + H] - col_sum[nc][nr]: # O(1)
            continue
        if row_sum[nr + H - 1][nc + W] - row_sum[nr + H - 1][nc]: # O(1)
            continue
        if col_sum[nc + W - 1][nr + H] - col_sum[nc + W - 1][nr]: # O(1)
            continue
        visited[nr][nc] = visited[r][c] + 1
        queue.append((nr, nc))

print(visited[Fr][Fc])