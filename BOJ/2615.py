dx = [1, -1, 0, 1]
dy = [1, 1, 1, 0]
MAX = 19

def in_board(x, y):
    return 0 <= x < MAX and 0 <= y < MAX

def solve(board, x, y):
    for i in range(4):
        lx, ly = x, y
        rx, ry = x, y
        while in_board(lx, ly) and board[ly][lx] == board[y][x]:
            lx -= dx[i]
            ly -= dy[i]
        while in_board(rx, ry) and board[ry][rx] == board[y][x]:
            rx += dx[i]
            ry += dy[i]
        if abs(rx - lx) == 6 or abs(ry - ly) == 6:
            return True
    return False

def main():
    board = [list(map(int, input().split())) for _ in range(19)]
    for x in range(MAX):
        for y in range(MAX):
            if not board[y][x]:
                continue
            if solve(board, x, y):
                print(board[y][x])
                print(y + 1, x + 1)
                return
    print(0)

if __name__ == '__main__':
    main()