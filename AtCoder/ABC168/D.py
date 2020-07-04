import sys
input = sys.stdin.readline

N, M = map(int, input().split())

adj = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)

vst = [-1] * N
q = [0]
vst[0] = 0
cnt = 0
for u in q:
    cnt += 1
    for v in adj[u]:
        if vst[v] < 0:
            vst[v] = u
            q.append(v)

if cnt == N:
    print('Yes')
    for k in vst[1:]:
        print(k + 1)

else:
    print('No')