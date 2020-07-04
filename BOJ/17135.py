from copy import deepcopy

N, M, D = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(N)]

def hunt(h, C):
    for d in range(1, D + 1):
        for dx in range(-d, d + 1):
            x, y = h + dx, N - (d - abs(dx))
            if 0 <= x < M and 0 <= y < N and C[y][x]: return x, y

def sol(H):
    C = deepcopy(B)
    ret = 0
    for _ in range(N):
        E = set(hunt(h, C) for h in H) - {None}
        ret += len(E)
        for x, y in E: C[y][x] = 0
        for y in range(N - 1, 0, -1): C[y] = C[y - 1][:]
        C[0] = [0] * M
    return ret

print(max(sol([i, j, k]) for i in range(M - 2) for j in range(i + 1, M - 1) for k in range(j + 1, M)))