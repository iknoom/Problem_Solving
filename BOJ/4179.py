dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

INF = 2000000

def is_out(x, y):
    if 0 <= x < C and 0 <= y < R:
        return False
    return True

def bfs():
    queue = []
    Jx, Jy = -1, -1
    for y in range(R):
        for x in range(C):
            if board[y][x] == 'F':
                queue.append(('F', x, y))
                vst[y][x] = INF
            elif board[y][x] == 'J':
                Jx, Jy = x, y
    vst[Jy][Jx] = 0
    queue.append(('J', Jx, Jy))
    for JF, x, y in queue:
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            if is_out(x1, y1):
                if JF == 'J':
                    return vst[y][x] + 1
                else:
                    continue
            if board[y1][x1] == '#' or vst[y1][x1] >= 0:
                continue
            vst[y1][x1] = vst[y][x] + 1
            queue.append((JF, x1, y1))
    return -1


if __name__ == '__main__':
    R, C = map(int, input().split())
    board = [input() for _ in range(R)]
    vst = [[-1] * C for _ in range(R)]
    answer = bfs()
    if answer < 0:
        print("IMPOSSIBLE")
    else:
        print(answer)