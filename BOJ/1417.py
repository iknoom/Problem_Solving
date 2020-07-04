from heapq import *
N = int(input())
A = [-int(input()) for _ in range(N)]
D = A[0]
hq = A[1:]
heapify(hq)
while hq and D >= hq[0]:
    D -= 1; heappush(hq, heappop(hq) + 1)
print(A[0] - D)