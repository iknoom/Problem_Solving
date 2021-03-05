dx = [1, -1, 0, 0, 1, 1, -1, -1, 0]
dy = [0, 0, 1, -1, 1, -1, 1, -1, 0]

N, M = map(int, input().split())
board = [[0] * M for _ in range(N)]
ax = ay = -1
bx = by = -1
for i in range(N):
    for j, v in enumerate(input()):
        if v == 'X':
            board[i][j] = -1
        elif v == 'A':
            ax = j
            ay = i
        elif v == 'B':
            bx = j
            by = i

# bfs
vst = set()
queue = [(ax, ay, bx, by, 0)]
vst.add((ax, ay, bx, by))
answer = -1
for _ax, _ay, _bx, _by, d in queue:
    if (_ax, _ay, _bx, _by) == (bx, by, ax, ay):
        answer = d
        break
    for i in range(9):
        for j in range(9):
            ax1, ay1 = _ax + dx[i], _ay + dy[i]
            bx1, by1 = _bx + dx[j], _by + dy[j]
            # 한 턴에 두 플레이어가 서로 교차하는 경로를 가지는 것은 안 된다.
            if (ax1, ay1) == (_bx, _by) and (bx1, by1) == (_ax, _ay): continue
            # 그리고 각 턴의 마지막에 두 플레이어는 같은 곳에 있으면 안 된다.
            if (ax1, ay1) == (bx1, by1): continue
            # 게임 판을 벗어나게 이동할 수는 없다.
            if ax1 < 0 or M <= ax1 or bx1 < 0 or M <= bx1: continue
            if ay1 < 0 or N <= ay1 or by1 < 0 or N <= by1: continue
            # 하지만, 벽으로 이동하거나,
            if board[ay1][ax1] < 0: continue
            if board[by1][bx1] < 0: continue
            if (ax1, ay1, bx1, by1) in vst: continue
            vst.add((ax1, ay1, bx1, by1))
            queue.append((ax1, ay1, bx1, by1, d + 1))

print(answer)