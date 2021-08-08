from sys import stdin
input = stdin.readline
from collections import deque
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
ddx = [-2, -2, -2, 2, 2, 2, -1, 0, 1, -1, 0, 1, 1, -1, 0, 0, 1, 1, -1, -1]
ddy = [-1, 0, 1, -1, 0, 1, -2, -2, -2, 2, 2, 2, 0, 0, 1, -1, 1, -1, 1, -1]

H, W = map(int, input().split())
board = [input().rstrip() for _ in range(H)]

queue = deque([])
vst = [[-1] * W for _ in range(H)]
queue.append((0, 0, 0))

def is_ok(x, y):
    return 0 <= x < W and 0 <= y < H

while queue:
    cx, cy, cnt = queue.popleft()
    if vst[cy][cx] >= 0:
        continue
    vst[cy][cx] = cnt
    for i in range(4):
        nx, ny = cx + dx[i], cy + dy[i]
        if not is_ok(nx, ny):
            continue
        if board[ny][nx] == '#':
            continue
        if vst[ny][nx] < 0 or vst[ny][nx] > cnt:
            queue.appendleft((nx, ny, cnt))
    for i in range(17):
        nx, ny = cx + ddx[i], cy + ddy[i]
        if not is_ok(nx, ny):
            continue
        if vst[ny][nx] < 0 or vst[ny][nx] > cnt + 1:
            queue.append((nx, ny, cnt + 1))

print(vst[-1][-1])