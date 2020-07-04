import sys
sys.setrecursionlimit(10**9)

V = [0] * 10001
L = [-1] * 10001
R = [-1] * 10001

def ist(u):
    p = 0
    while True:
        if V[u] < V[p]:
            if L[p] < 0: L[p] = u; return
            else: p = L[p]
        else:
            if R[p] < 0: R[p] = u; return
            else: p = R[p]

def dfs(u):
    if L[u]: dfs(L[u])
    if R[u]: dfs(R[u])
    print(V[u])

V[0] = int(input())
i = 1
while True:
    try:
        V[i] = int(input())
        ist(i)
        i += 1
    except:
        break
dfs(0)
