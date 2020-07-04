from heapq import *
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
adj = [[] for _ in range(N)]
ind = [0] * N
for _ in range(M):
	a,b = map(int,input().split())
	adj[a-1].append(b-1)
	ind[b-1] += 1

hq = []
for u in range(N):
	if not ind[u]: heappush(hq, u)

ans = []
for _ in range(N):
	u = heappop(hq)
	ans.append(u+1)
	for v in adj[u]:
		ind[v] -= 1
		if not ind[v]:
			heappush(hq, v)
			
print(*ans)
