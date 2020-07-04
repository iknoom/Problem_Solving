from heapq import *
import sys
input = sys.stdin.readline
INF = sys.maxsize

N, M = map(int, input().split())
adj = [[] for _ in range(N)]
for _ in range(M):
    u, v, w = map(int, input().split())
    adj[u - 1].append((v - 1, w))
    adj[v - 1].append((u - 1, w))
S, E = map(int, input().split())

L = [0] * N
hq = [(-INF, INF, S-1)]
while hq:
    d, l, u = heappop(hq)
    if L[u]: continue
    L[u] = min(-d, l)
    for v, w in adj[u]:
        heappush(hq, (-w, min(w,l), v))

print(L[E - 1])