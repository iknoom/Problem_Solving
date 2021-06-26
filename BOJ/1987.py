dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def is_in_board(x, y):
    return 0 <= x < C and 0 <= y < R

def dfs(x, y, visited):
    if visited & (1 << (ord(board[y][x]) - ord('A'))):
        return 0
    ret = 0
    visited |= 1 << (ord(board[y][x]) - ord('A'))
    for i in range(4):
        x2, y2 = x + dx[i], y + dy[i]
        if not is_in_board(x2, y2):
            continue
        ret = max(ret, dfs(x2, y2, visited))
    return ret + 1


if __name__ == '__main__':
    R, C = map(int, input().split())
    board = [input() for _ in range(R)]
    answer = dfs(0, 0, 0)
    print(answer)
