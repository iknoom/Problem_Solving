from collections import deque
from sys import stdin
input = stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def rotate_all(x, d, k):
    if d == 1:
        k = M - k
    for i in range(x - 1, N, x):
        board[i].rotate(k)

def delete_same():
    tmp = set()
    for y in range(N):
        for x in range(M):
            if not board[y][x]: continue
            for i in range(4):
                x1, y1 = (x + dx[i]) % M, y + dy[i]
                if y1 < 0 or N <= y1: continue
                if board[y][x] == board[y1][x1]:
                    tmp.add((x, y))
                    tmp.add((x1, y1))
    if not tmp:
        return False
    for x, y in tmp:
        board[y][x] = 0
    return True

def inc_dec_all():
    S = 0
    C = 0
    for y in range(N):
        for x in range(M):
            if not board[y][x]: continue
            S += board[y][x]
            C += 1
    for y in range(N):
        for x in range(M):
            if not board[y][x]: continue
            if board[y][x] * C > S: board[y][x] -= 1
            elif board[y][x] * C < S: board[y][x] += 1

if __name__ == '__main__':
    N, M, T = map(int, input().split())
    board = [deque(map(int, input().split())) for _ in range(N)]
    for _ in range(T):
        x, d, k = map(int, input().split())
        rotate_all(x, d, k)
        if not delete_same():
            inc_dec_all()
    print(sum(sum(board[i]) for i in range(N)))