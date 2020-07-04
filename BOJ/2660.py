N = int(input())
adj = [[] for _ in range(N)]
while True:
    a, b = map(int, input().split())
    if a + b < 0: break
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)

def bfs(i):
    q = [(i, 0)]
    vst = [-1] * N
    vst[i] = 0
    for u, c in q:
        for v in adj[u]:
            if vst[v] < 0:
                vst[v] = c + 1
                q.append((v, c + 1))
    return max(vst)

ret = list(bfs(i) for i in range(N))
M = min(ret)
ans = [i + 1 for i in range(N) if ret[i] == M]
print(M, len(ans))
print(*ans)