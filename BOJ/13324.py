# https://jwvg0425-ps.tistory.com/98

from heapq import *

N = int(input())
A = list(map(int, input().split()))

hq = [-A[0]]
t = 0
ans = [A[0]]

for i in range(1, N):
    t += 1
    top = -hq[0]
    r = top + t
    if r <= A[i]:
        heappush(hq, -(A[i] - t))
    else:
        heappop(hq)
        heappush(hq, -(A[i] - t))
        heappush(hq, -(A[i] - t))
    ans.append(-hq[0] + t)

for i in range(N - 2, -1, -1):
    if ans[i] >= ans[i + 1]:
        ans[i] = ans[i + 1] - 1

print(*ans, sep='\n')