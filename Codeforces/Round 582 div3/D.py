from heapq import *
N, K = map(int,input().split())
heap = []
for i in list(map(int,input().split())):
    heap.append((-i, 0))
heapify(heap)
cnt = 1
div_cnt = 0
prv = -1
ans = 10**10
while heap:
    num, div_c = heappop(heap)
    num = -num
    if prv == num:
        cnt += 1
        div_cnt += div_c
    else:
        prv = num
        div_cnt = div_c
        cnt = 1
    if cnt == K:
        ans = min(ans, div_cnt)
    if num:
        heappush(heap, ( - (num>>1), div_c + 1)  )
print(ans)