N, M, H = map(int, input().split())
L = [[0] * N for _ in range(H)]
ans = 4

for _ in range(M):
    a, b = map(int, input().split())
    L[a - 1][b - 1] = 1

def do():
    p = list(range(N))
    for i in range(H):
        for j in range(N - 1):
            if L[i][j]: p[j], p[j + 1] = p[j + 1], p[j]
    return all(p[i] == i for i in range(N))

def sol(y, d):
    global ans
    if do(): ans = min(ans, d)
    if d == 3: return
    for i in range(y, H):
        for j in range(N - 1):
            if L[i][j] or (j > 0 and L[i][j - 1]) or (j < N - 2 and L[i][j + 1]): continue
            L[i][j] = 1; sol(i, d + 1); L[i][j] = 0

sol(0, 0)
print(ans if ans != 4 else -1)