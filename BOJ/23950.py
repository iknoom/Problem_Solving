from heapq import *
from sys import stdin
input = stdin.readline


def solution(n, arr):
    ret = []
    hq = []
    for x in arr:
        heappush(hq, x)
        if len(hq) > hq[0]:
            heappop(hq)
        ret.append(len(hq))
    return ret


if __name__ == "__main__":
    T = int(input())
    for testcase in range(1, T + 1):
        n = int(input())
        arr = list(map(int, input().split()))
        answer = solution(n, arr)
        print(f'Case #{testcase}:', *answer)