from sys import stdin
from collections import defaultdict
input = stdin.readline


def solution():
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    min_idx = {}
    for i in range(N):
        if A[i] in min_idx:
            continue
        min_idx[A[i]] = i + 1
    queries = list(map(int, input().split()))
    answer = []
    for t in queries:
        answer.append(min_idx[t])
        for color in min_idx.keys():
            if color != t and min_idx[t] > min_idx[color]:
                min_idx[color] += 1
        min_idx[t] = 1
    print(*answer)


if __name__ == '__main__':
    solution()