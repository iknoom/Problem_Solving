# https://jwvg0425-ps.tistory.com/98

from heapq import *

N = int(input())
A = list(map(int, input().split()))

hq = [-A[0]]
t = 0
ans = 0

for i in range(1, N):
    t += 1
    top = -hq[0]
    r = top + t
    if r <= A[i]:
        heappush(hq, -(A[i] - t))
    else:
        ans += r - A[i]
        heappop(hq)
        heappush(hq, -(A[i] - t))
        heappush(hq, -(A[i] - t))

print(ans)