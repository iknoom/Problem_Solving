from heapq import *

N = int(input())
a = list(map(int, input().split()))

answer = sum(a)
degree = [1] * N
hq = [(a[i] * (2 * degree[i] + 1), i) for i in range(N)]
heapify(hq)

for _ in range(N - 2):
    inc, i = heappop(hq)
    answer += inc
    degree[i] += 1
    heappush(hq, (a[i] * (2 * degree[i] + 1), i))

if N == 1:
    print(0)
else:
    print(answer)