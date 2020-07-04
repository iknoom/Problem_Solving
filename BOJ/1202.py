import sys, heapq
input = sys.stdin.readline

N, K = map(int, input().split())
INF = float('inf')
ALL = []
for _ in range(N):
    M, V = map(int, input().split())
    ALL.append((M, V))
for _ in range(K):
    C = int(input())
    ALL.append((C, INF))

ALL.sort(reverse=True)
bag = 0
pq = []

for M, V in ALL:
    if V == INF:
        bag += 1
    else:
        heapq.heappush(pq, V)
        if len(pq) > bag:
            heapq.heappop(pq)

print(sum(pq))