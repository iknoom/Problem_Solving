import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int,input().split())
adj = [[] for _ in range(M * 2 + 1)]
SCCn = [0] * (M * 2 + 1)
DFSn = [0] * (M * 2 + 1)
d_n = s_n = 0
st = []

for _ in range(N):
    a, b = map(int,input().split())
    adj[M - a].append(M + b)
    adj[M - b].append(M + a)

def dfs(u):
    global d_n, s_n
    d_n += 1
    ret = DFSn[u] = d_n
    st.append(u)
    for v in adj[u]:
        if not DFSn[v]: ret = min(ret, dfs(v))
        elif not SCCn[v]: ret = min(ret, DFSn[v])

    if ret == DFSn[u]:
        s_n += 1
        while True:
            v = st.pop()
            SCCn[v] = s_n
            if v == u: break

    return ret


for i in range(1, M+1):
    if not DFSn[M + i]: dfs(M + i)
    if not DFSn[M - i]: dfs(M - i)

ans = '^_^'
for i in range(1, M+1):
    if SCCn[M + i] == SCCn[M - i]:
        ans = 'OTL'

print(ans)