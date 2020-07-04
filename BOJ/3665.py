from collections import deque
import sys
input = sys.stdin.readline

for _ in range(int(input())):
	N = int(input())
	adj = [set() for _ in range(N)]
	cnt = [0] * N
	
	tmp = list(map(int,input().split()))
	for i in range(N-1):
		u = tmp[i] - 1
		for j in range(i+1, N):
			v = tmp[j] - 1
			adj[u].add(v)
			cnt[v] += 1
			
			
	M = int(input())
	for _ in range(M):
		u, v = map(int,input().split())
		if v-1 in adj[u-1]:
			adj[u-1].discard(v-1)
			adj[v-1].add(u-1)
			cnt[v-1] -= 1
			cnt[u-1] += 1
		else:
			adj[v-1].discard(u-1)
			adj[u-1].add(v-1)
			cnt[u-1] -= 1
			cnt[v-1] += 1
	
	q = deque([])
	for i in range(N):
		if not cnt[i]:
			q.append(i)
	
	ans = []
	for _ in range(N):
		if not q:
			ans = ["IMPOSSIBLE"]
			break
		if len(q) > 1:
			ans = ["?"]
			break
		u = q.popleft()
		ans.append(u+1)
		for v in adj[u]:
			cnt[v] -= 1
			if not cnt[v]:
				q.append(v)
				
	print(*ans)
