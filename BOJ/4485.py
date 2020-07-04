import sys
from heapq import *
input = sys.stdin.readline
INF = sys.maxsize

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
problem = 1

while True:
    N = int(input())
    if not N: break
    B = [list(map(int,input().split())) for _ in range(N)]
    hq = [(B[0][0], 0, 0)]
    dist = [[INF] * N for _ in range(N)]
    dist[0][0] = B[0][0]
    while hq:
        d, x, y = heappop(hq)
        for i in range(4):
            xx, yy = x + dx[i], y + dy[i]
            if 0 <= xx < N and 0 <= yy < N:
                if d + B[yy][xx] < dist[yy][xx]:
                    dist[yy][xx] = d + B[yy][xx]
                    heappush(hq, (d + B[yy][xx], xx, yy))
    print(f"Problem {problem}:", dist[-1][-1])
    problem += 1