from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(10**6)

def is_valid():
    for i in range(N):
        if degree[i] % 2:
            return False
    return True

def dfs(u):
    for v in adj[u]:
        while adj[u][v]:
            adj[u][v] -= 1
            adj[v][u] -= 1
            dfs(v)
    print(u + 1, end=' ')

if __name__ == '__main__':
    N = int(input())
    degree = [0] * N
    adj = [{} for _ in range(N)]
    for i in range(N):
        for j, v in enumerate(map(int, input().split())):
            if i >= j: continue
            if v == 0: continue
            adj[j][i] = v
            adj[i][j] = v
            degree[i] += v
            degree[j] += v

    # check vaild
    if not is_valid():
        print(-1)
    else:
        # print solution
        start = -1
        for i in range(N):
            if degree[i]:
                start = i
                break
        dfs(start)
