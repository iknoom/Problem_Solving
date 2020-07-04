from collections import deque
import sys
input = sys.stdin.readline

for _ in range(int(input())):
	N, K = map(int,input().split())
	T = list(map(int,input().split()))
	adj = [[] for _ in range(N)]
	cnt = [0] * N
	ans = [0] * N
	
	for _ in range(K):
		u, v = map(int,input().split())
		adj[u-1].append(v-1)
		cnt[v-1] += 1
	
	W = int(input())
	
	q = deque([])
	for u in range(N):
		if not cnt[u]: q.append(u)
		
	for _ in range(N):
		u = q.popleft()
		ans[u] += T[u]
		for v in adj[u]:
			cnt[v] -= 1
			ans[v] = max(ans[v], ans[u])
			if not cnt[v]:
				q.append(v)
				
	print(ans[W-1])
