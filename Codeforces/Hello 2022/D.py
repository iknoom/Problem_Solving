import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(2 * n)]
    corner = [
        board[0][n], board[0][-1],
        board[n - 1][n], board[n - 1][-1],
        board[n][0], board[n][n - 1],
        board[-1][0], board[-1][n - 1]
    ]
    answer = min(corner)
    for i in range(n, 2 * n):
        for j in range(n, 2 * n):
            answer += board[i][j]
    print(answer)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()