from sys import stdin
input = stdin.readline
dx = [1, -1, 0, 0, 1, 1, -1, -1]
dy = [0, 0, 1, -1, 1, -1, 1, -1]

while True:
    R, C = map(int, input().split())
    if R + C == 0:
        break
    board = [list(input().rstrip()) for _ in range(R)]
    for y in range(R):
        for x in range(C):
            if board[y][x] == '*':
                continue
            cnt = 0
            for i in range(8):
                x1, y1 = x + dx[i], y + dy[i]
                if 0 <= x1 < C and 0 <= y1 < R:
                    cnt += int(board[y1][x1] == '*')
            board[y][x] = str(cnt)
    for row in board:
        print(''.join(row))