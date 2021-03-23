dx = [1, -1, 0, 0, 1, 1, -1, -1]
dy = [0, 0, 1, -1, 1, -1, 1, -1]

QUESTION = 10
MINE = 11
CLEAR = 12

def is_ok(N, x, y):
    return 0 <= x < N and 0 <= y < N

def check(N, board, x, y):
    mine = []
    question = []
    for i in range(8):
        x1, y1 = x + dx[i], y + dy[i]
        if not is_ok(N, x1, y1):
            continue
        if board[y1][x1] == QUESTION:
            question.append((x1, y1))
        if board[y1][x1] == MINE:
            mine.append((x1, y1))
    if len(mine) == board[y][x]:
        if question:
            for x1, y1 in question:
                board[y1][x1] = CLEAR
            return True
    if len(mine) + len(question) == board[y][x]:
        if question:
            for x1, y1 in question:
                board[y1][x1] = MINE
            return True
    return False

def solution(N, board):
    while True:
        flag = False
        for i in range(N):
            for j in range(N):
                if check(N, board, j, i):
                    flag = True
        if not flag:
            break
    ret = 0
    for i in range(N):
        for j in range(N):
            if board[i][j] in [QUESTION, MINE]:
                ret += 1
    return ret

if __name__ == '__main__':
    N = int(input())
    board = [[] for _ in range(N)]
    for i in range(N):
        row = input()
        for e in row:
            if e == '#':
                board[i].append(QUESTION)
            else:
                board[i].append(int(e))
    answer = solution(N, board)
    print(answer)