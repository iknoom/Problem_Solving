import sys
sys.setrecursionlimit(300001)

def dfs(u, a, adj, vst):
    ret = 0
    vst[u] = True
    for v in adj[u]:
        if vst[v]: continue
        ret += dfs(v, a, adj, vst)
        ret += abs(a[v])
        a[u] += a[v]
    return ret

def solution(a, edges):
    N = len(a)
    adj = [[] for _ in range(N)]
    vst = [False] * N
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    answer = dfs(0, a, adj, vst)
    if a[0] == 0:
        return answer
    else:
        return -1
