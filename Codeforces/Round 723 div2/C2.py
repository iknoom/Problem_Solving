from sys import stdin
from heapq import *
input = stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))
    answer = -1

    cur = 0
    hp = 0
    hq = []
    for k in a:
        if k >= 0:
            hp += k
            cur += 1
            answer = max(answer, cur)
        # negative
        else:
            hp += k
            cur += 1
            heappush(hq, k)
            while hp < 0:
                x = heappop(hq)
                cur -= 1
                hp -= x
            answer = max(answer, cur)
    print(answer)


if __name__ == '__main__':
    solution()