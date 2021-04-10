import heapq
from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N = int(input())
    ST = [tuple(map(int, input().split())) for _ in range(N)]
    answer = [-1] * N

    hq = [(0, 1)]
    for i, s, e in sorted(ST, key=lambda x: x[1]):
        if hq[0][0] > s:
            answer[i - 1] = len(hq) + 1
            heapq.heappush(hq, (e, len(hq) + 1))
        else:
            _, cur = heapq.heappop(hq)
            answer[i - 1] = cur
            heapq.heappush(hq, (e, cur))

    print(len(hq))
    print(*answer, sep='\n')