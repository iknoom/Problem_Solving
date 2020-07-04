import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(u, root):
    global ans
    v = adj[u] - 1
    ret = -1
    if visited[v] < 0:
        visited[v] = root
        ret = dfs(v, root)
    elif visited[v] == root:
        ret = v
    if ret >= 0:
        ans += 1
    if ret == u:
        ret = -1
    return ret


T = int(input())

for _ in range(T):
    N = int(input())
    adj = list(map(int, input().split()))
    visited = [-1] * N
    ans = 0
    for u in range(N):
        if visited[u] < 0:
            visited[u] = u
            dfs(u, u)
    print(N - ans)