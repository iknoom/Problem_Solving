import sys, heapq
input = sys.stdin.readline
INF = sys.maxsize

def dijkstra(N, S, D, in_adj, out_adj):
    dist = [INF] * N
    dist[S] = 0
    hq = [(0, S)]
    while hq:
        _, u = heapq.heappop(hq)
        for v, w in out_adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(hq, (-dist[v], v))
    if dist[D] == INF: return -1

    q = [D]
    vst = [False] * N
    vst[D] = True
    for u in q:
        for v, w in in_adj[u]:
            if dist[v] + w == dist[u]:
                out_adj[v].discard((u, w))
                if not vst[v]:
                    vst[v] = True
                    q.append(v)
    return dist[D]


def solutino(N, M):
    S, D = map(int, input().split())
    out_adj = [set() for _ in range(N)]
    in_adj = [set() for _ in range(N)]

    for _ in range(M):
        u, v, w = map(int, input().split())
        out_adj[u].add((v, w))
        in_adj[v].add((u, w))

    _ = dijkstra(N, S, D, in_adj, out_adj)
    d = dijkstra(N, S, D, in_adj, out_adj)
    print(d)

def main():
    while True:
        N, M = map(int, input().split())
        if N == M == 0: break
        solutino(N, M)

if __name__ == "__main__":
    main()