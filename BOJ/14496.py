from sys import stdin
input = stdin.readline

def bfs(start, end):
    vst = [-1] * N
    vst[start] = 0
    q = [start]
    for u in q:
        if u == end:
            return vst[u]
        for v in adj[u]:
            if vst[v] >= 0:
                continue
            vst[v] = vst[u] + 1
            q.append(v)
    return -1

if __name__ == '__main__':
    a, b = map(int, input().split())
    N, M = map(int, input().split())
    adj = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
    answer = bfs(a - 1, b - 1)
    print(answer)