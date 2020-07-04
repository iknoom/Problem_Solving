from heapq import *

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

X = [A[i] - B[i] for i in range(N)]
Y = [B[i] - A[i] for i in range(N)]

iter = [(Y[i], X[i]) for i in range(N)]
iter.sort()

ans = 0
hq = []

for y, x in iter:
    while hq and hq[0] <= y:
        heappop(hq)
    ans += len(hq)
    heappush(hq, x)
print(ans)