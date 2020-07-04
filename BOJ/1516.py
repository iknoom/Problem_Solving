from collections import deque

N = int(input())
adj = [[] for _ in range(N)]
T = [0] * N
cnt = [0] * N
ans = [0] * N

for u in range(N):
	tmp = list(map(int,input().split()))
	T[u] = tmp[0]
	for v in tmp[1:-1]:
		adj[v-1].append(u)
		cnt[u] += 1

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
			
print(*ans, sep='\n')
