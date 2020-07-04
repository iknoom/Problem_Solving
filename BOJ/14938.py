from heapq import *

n, m, r = map(int, input().split())
T = list(map(int, input().split()))
adj = [[] for _ in range(n)]

for _ in range(r):
    u, v, w = map(int, input().split())
    adj[u - 1].append((v - 1, w))
    adj[v - 1].append((u - 1, w))

def dijk(s):
    D = [10**9] * n
    D[s] = 0
    hq = [(0, s)]
    while hq:
        l, u = heappop(hq)
        for v, w in adj[u]:
            if D[u] + w < D[v]:
                D[v] = D[u] + w
                heappush(hq, (D[v], v))
    return sum(T[i] for i in range(n) if D[i] <= m)

print(max(dijk(i) for i in range(n)))