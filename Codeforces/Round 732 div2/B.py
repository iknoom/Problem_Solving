from sys import stdin
from collections import Counter
input = stdin.readline


def solution():
    n, m = map(int, input().split())
    originals = [input().rstrip() for _ in range(n)]
    reordereds = [input().rstrip() for _ in range(n - 1)]
    answer = []
    for i in range(m):
        S1 = Counter([originals[j][i] for j in range(n)])
        S2 = Counter([reordereds[j][i] for j in range(n - 1)])
        for k in (S1 - S2).keys():
            answer.append(k)
    print(''.join(answer))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()