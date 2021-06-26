dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def is_in_board(x, y):
    return 0 <= x < M and 0 <= y < N

def solution():
    vst = [[-1] * M for _ in range(N)]
    # fill queue
    queue = []
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                queue.append((j, i))
                vst[i][j] = 0
    # bfs
    answer = -1
    for x, y in queue:
        answer = vst[y][x]
        for i in range(4):
            x2, y2 = x + dx[i], y + dy[i]
            if not is_in_board(x2, y2):
                continue
            if board[y2][x2] == -1:
                continue
            if vst[y2][x2] >= 0:
                continue
            vst[y2][x2] = vst[y][x] + 1
            queue.append((x2, y2))
    # check
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0 and vst[i][j] < 0:
                answer = -1
    return answer


if __name__ == '__main__':
    M, N = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(N)]
    answer = solution()
    print(answer)