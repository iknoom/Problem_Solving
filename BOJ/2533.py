import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def dfs(u):
    a = 1
    b = 0
    for v in adj[u]:
        if vst[v]: continue
        vst[v] = True
        a_i, b_i = dfs(v)
        a += min(a_i, b_i)
        b += a_i
    return a, b

if __name__ == "__main__":
    N = int(input())
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    vst = [False] * N
    if N == 0:
        print(1)
    else:
        vst[0] = True
        a, b = dfs(0)
        print(min(a, b))