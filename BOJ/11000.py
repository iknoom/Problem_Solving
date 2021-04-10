import heapq
from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N = int(input())
    ST = [tuple(map(int, input().split())) for _ in range(N)]
    hq = [0]

    for s, e in sorted(ST):
        if hq[0] > s:
            heapq.heappush(hq, e)
        else:
            heapq.heappop(hq)
            heapq.heappush(hq, e)
    print(len(hq))