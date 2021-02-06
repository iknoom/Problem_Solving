from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(10**4)

def find(u):
    if p[u] != u:
        p[u] = find(p[u])
    return p[u]

N, M = map(int, input().split())
C = input().split()
adj = [tuple(map(int, input().split())) for _ in range(M)]
p = [i for i in range(N)]
adj.sort(key=lambda x: x[2])
ans = 0
for u, v, w in adj:
    u -= 1
    v -= 1
    if C[u] == C[v]:
        continue
    if find(u) == find(v):
        continue
    ans += w
    p[find(u)] = find(v)

if len(set(find(i) for i in range(N))) == 1:
    print(ans)
else:
    print(-1)