from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def in_board(x, y):
    return 0 <= x < M and 0 <= y < N

def bfs(start, end):
    vst = [[-1] * M for _ in range(N)]
    queue = deque([])
    # 1.
    x, y = start
    queue.append(start)
    vst[y][x] = 0
    # 2.
    while len(queue) > 0:
        x, y = queue.popleft()
        for i in range(4):
            x2, y2 = x + dx[i], y + dy[i]
            if in_board(x2, y2) and vst[y2][x2] == -1 and board[y2][x2] == '1':
                vst[y2][x2] = vst[y][x] + 1
                queue.append((x2, y2))
    x, y = end
    return vst[y][x] + 1


if __name__ == '__main__':
    # input
    N, M = map(int, input().split())
    board = [input() for _ in range(N)]

    # bfs
    start = (0, 0)
    end = (M - 1, N - 1)
    answer = bfs(start, end)
    if answer == -1:
        print(answer)
    else:
        print(answer + 1)