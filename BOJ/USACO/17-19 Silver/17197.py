import sys
input = sys.stdin.readline

N, M = map(int,input().split())
xy = [tuple(map(int,input().split())) for _ in range(N)]
adj = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int,input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)

vst = [False] * N
ans = 1e9
for i in range(N):
    if not vst[i]:
        q = [i]
        vst[i] = True
        x1 = x2 = xy[i][0]
        y1 = y2 = xy[i][1]
        for u in q:
            for v in adj[u]:
                if not vst[v]:
                    vst[v] = True
                    x, y = xy[v]
                    x1, x2 = min(x1, x), max(x2, x)
                    y1, y2 = min(y1, y), max(y2, y)
                    q.append(v)
        ans = min(ans, 2 * (x2 - x1 + y2 - y1))
print(ans)

