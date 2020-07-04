import sys
from heapq import *
input = sys.stdin.readline
INF = sys.maxsize

N = int(input())
M = int(input())
adj = [[] for _ in range(N)]
for _ in range(M):
    u, v, w = map(int, input().split())
    adj[u - 1].append((v - 1, w))

S, E = map(int, input().split())
S -= 1
E -= 1
dist = [INF] * N
prv = [-1] * N

dist[S] = 0
hq = [(0, S)]

while hq:
    d, u = heappop(hq)
    for v, w in adj[u]:
        if d + w < dist[v]:
            dist[v] = d + w
            prv[v] = u
            heappush(hq, (d + w, v))
ans = []
t = E
while t >= 0:
    ans.append(t + 1)
    t = prv[t]
print(dist[E])
print(len(ans))
print(*ans[::-1])