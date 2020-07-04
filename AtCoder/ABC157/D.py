import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
friend = [[] for _ in range(N)]
block = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    friend[a - 1].append(b - 1)
    friend[b - 1].append(a - 1)

for _ in range(K):
    a, b = map(int, input().split())
    block[a - 1].append(b - 1)
    block[b - 1].append(a - 1)

vst = [0] * N
SIZE = []
C = 0
for i in range(N):
    if not vst[i]:
        C += 1
        vst[i] = C
        q = [i]
        cnt = 0
        for u in q:
            cnt += 1
            for v in friend[u]:
                if not vst[v]:
                    vst[v] = C
                    q.append(v)
        SIZE.append(cnt)

for i in range(N):
    ret = SIZE[vst[i] - 1] - 1
    ret -= len(friend[i])
    for b in block[i]:
        if vst[i] == vst[b]:
            ret -= 1
    print(ret, end=' ')
print()
