from heapq import *
N, K = map(int, input().split())
V = sorted(map(int, input().split()))

hq = []
hq_d = []

for i in range(N - K - 1):
    heappush(hq, V[i + 1] - V[i])
ans = hq[0] + (V[N - K - 1] - V[0])

for i in range(K):
    M = V[N - K + i] - V[i + 1]
    heappush(hq_d, V[i + 1] - V[i])
    heappush(hq, V[N - K + i] - V[N - K + i - 1])
    while hq_d and hq[0] == hq_d[0]:
        heappop(hq)
        heappop(hq_d)
    m = hq[0]
    ans = min(ans, M + m)

print(ans)

