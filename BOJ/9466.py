import sys
sys.setrecursionlimit(10**5 + 5)
input = sys.stdin.readline

def dfs(u, adj, visited):
    v = adj[u]
    if not visited[v]:
        visited[v] = True
        return dfs(v, adj, visited)
    else:
        return v


def solution():
    N = int(input())
    adj = list(map(int, input().split()))
    for i in range(N):
        adj[i] -= 1

    # solution
    visited = [False] * N
    count = 0
    for u in range(N):
        if not visited[u]:
            visited[u] = True
            end = dfs(u, adj, visited)
            while u != end:
                count += 1
                u = adj[u]
    return count


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        answer = solution()
        print(answer)