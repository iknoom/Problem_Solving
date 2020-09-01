from copy import deepcopy
from itertools import permutations
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def rotate(B, r, c, s):
    for s1 in range(1, s + 1):
        x, y = c - s1, r - s1
        t = B[y][x]
        for i in range(4):
            for _ in range(s1 * 2):
                x += dx[i]
                y += dy[i]
                t, B[y][x] = B[y][x], t

def sol(B, P):
    global T
    for i in P:
        r, c, s = T[i]
        rotate(B, r - 1, c - 1, s)
    return min(sum(row) for row in B)

if __name__ == "__main__":
    N, M, K = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(N)]
    T = [tuple(map(int, input().split())) for _ in range(K)]
    print(min(sol(deepcopy(A), p) for p in permutations(range(K))))
