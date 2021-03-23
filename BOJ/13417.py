from sys import stdin
from collections import deque
input = stdin.readline


def solution():
    N = int(input())
    answer = deque([])
    for c in input().split():
        if not answer:
            answer.append(c)
        elif answer[0] >= c:
            answer.appendleft(c)
        else:
            answer.append(c)
    print(''.join(answer))

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()