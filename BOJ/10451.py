import sys
sys.setrecursionlimit(1001)

def dfs(u, root):
    v = adj[u] - 1
    if visited[v] < 0:          # 방문 X -> 재귀호출
        visited[v] = root
        return dfs(v, root)
    elif visited[v] == root:    # 방문 O && 같은 root
        return 1
    else:                       # 방문 O && 다른 root
        return 0


T = int(input())

for _ in range(T):
    N = int(input())
    adj = list(map(int, input().split()))
    visited = [-1] * N
    ans = 0
    for root in range(N):
        if visited[root] < 0:
            visited[root] = root
            ans += dfs(root, root)
    print(ans)