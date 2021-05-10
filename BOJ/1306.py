from heapq import *

N, M = map(int, input().split())
light = list(map(int, input().split()))

hq = []
del_hq = []
L = M * 2 - 1

answer = []
for i in range(L):
    heappush(hq, -light[i])

for i in range(L, N):
    answer.append(-hq[0])
    heappush(hq, -light[i])
    heappush(del_hq, -light[i - L])
    while del_hq and hq[0] == del_hq[0]:
        heappop(hq)
        heappop(del_hq)
answer.append(-hq[0])
print(*answer)