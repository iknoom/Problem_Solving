from sys import stdin
input = stdin.readline

def bfs(s):
    ret = dist[s]
    queue = [s]
    for u in queue:
        for v, w in adj[u]:
            if dist[v] >= 0: continue
            dist[v] = dist[u] + w
            ret = max(ret, dist[v])
            queue.append(v)
    return ret

def dfs(s):
    ret = dist[s]
    stack = [s]
    while stack:
        u = stack.pop()
        for v, w in adj[u]:
            if dist[v] >= 0: continue
            dist[v] = dist[u] + w
            ret = max(ret, dist[v])
            stack.append(v)
    return ret

def dfs2(u):
    ret = dist[u]
    for v, w in adj[u]:
        if dist[v] < 0:
            dist[v] = dist[u] + w
            ret = max(ret, dfs2(v))
    return ret

if __name__ == "__main__":
    # input
    N, R = map(int, input().split())
    adj = [[] for _ in range(N)]
    dist = [-1] * N
    for _ in range(N - 1):
        a, b, d = map(int, input().split())
        adj[a - 1].append((b - 1, d))
        adj[b - 1].append((a - 1, d))

    # get giga
    giga = R - 1
    dist[giga] = 0
    while True:
        nxt = [(v, w) for v, w in adj[giga] if dist[v] < 0]
        if len(nxt) != 1: break
        v, w = nxt[0]
        dist[v] = dist[giga] + w
        giga = v

    # Graph Search
    ans = bfs(giga)
    # ans = dfs(giga)
    # ans = dfs2(giga)

    print(dist[giga], ans - dist[giga])