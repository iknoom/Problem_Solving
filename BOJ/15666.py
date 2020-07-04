_, M = map(int, input().split())
X = sorted(set(map(int, input().split())))
N = len(X)

def sol(i, S):
    global N, M
    if len(S) == M: print(*S); return
    for j in range(i, N):
        sol(j, S+[X[j]])

sol(0, [])