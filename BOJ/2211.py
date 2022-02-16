import heapq
from sys import stdin
input = stdin.readline
INF = 1e18

def get_tree(start):
    dist = [INF] * N
    prev = [-1] * N
    dist[start] = 0
    hq = [(0, start)]
    while len(hq) > 0:
        d, u = heapq.heappop(hq)
        if dist[u] < d:
            continue
        for v, w in adj_list[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                prev[v] = u
                heapq.heappush(hq, (dist[v], v))
    return prev

N, M = map(int, input().split())
adj_list = [[] for _ in range(N)]
for _ in range(M):
    u, v, w = map(int, input().split())
    adj_list[u - 1].append((v - 1, w))
    adj_list[v - 1].append((u - 1, w))

tree = get_tree(0)
print(N - 1)
for i in range(N):
    if tree[i] >= 0:
        print(i + 1, tree[i] + 1)
