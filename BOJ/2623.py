from collections import deque

N, M = map(int,input().split())
adj = [[] for _ in range(N)]
cnt = [0] * N
for _ in range(M):
	t = list(map(int,input().split()))
	for i in range(1, t[0]):
		u, v = t[i], t[i + 1]
		adj[u-1].append(v-1)
		cnt[v-1] += 1

q = deque([])
for i in range(N):
	if not cnt[i]: q.append(i)

ans = []

for _ in range(N):
	if not q:
		print(0)
		exit()
	u = q.popleft()
	ans.append(u+1)
	for v in adj[u]:
		cnt[v] -= 1
		if not cnt[v]:
			q.append(v)

print(*ans, sep='\n')
