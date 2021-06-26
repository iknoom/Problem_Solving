from sys import setrecursionlimit
setrecursionlimit(10 ** 6 + 5)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y):
    visited[y][x] = True
    for i in range(4):
        x2, y2 = x + dx[i], y + dy[i]
        if 0 <= x2 < M and 0 <= y2 < N and board[y2][x2] == '0' and not visited[y2][x2]:
            dfs(x2, y2)


if __name__ == '__main__':
    N, M = map(int,input().split())
    board = [input() for _ in range(N)]
    visited = [[False] * M for _ in range(N)]

    for i in range(M):
        if board[0][i] == '0':
            dfs(i, 0)

    answer = False
    for i in range(M):
        if visited[-1][i]:
            answer = True
    if answer:
        print('YES')
    else:
        print('NO')