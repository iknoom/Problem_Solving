import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def dfs(u):
	global d_n, s_n
	d_n += 1
	ret = DFSn[u] = d_n
	st.append(u)
	for v in adj[u]:
		if not DFSn[v]: ret = min(ret, dfs(v))
		elif not SCCn[v]: ret = min(ret, DFSn[v])
	if DFSn[u] == ret:
		s_n += 1
		while True:
			v = st.pop()
			SCCn[v] = s_n
			if v == u: break
	return ret
	

for _ in range(int(input())):
	N, M = map(int,input().split())
	adj = [[] for _ in range(N)]
	SCCn = [0] * (N)
	DFSn = [0] * (N)
	st = []
	d_n = s_n = 0
	for _ in range(M):
		a, b = map(int,input().split())
		adj[a - 1].append(b - 1)
	for i in range(N):
		if not DFSn[i]:
			dfs(i)
	
	scc_ind = [0] * s_n
	for u in range(N):
		u_n = SCCn[u] - 1
		for v in adj[u]:
			v_n = SCCn[v] - 1
			if u_n != v_n:
				scc_ind[v_n] += 1
	print(scc_ind.count(0))
