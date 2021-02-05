import sys
from collections import Counter

input = sys.stdin.readline


def solution():
    x, y = map(int, input().split())
    LR = input().rstrip()
    ALL = Counter(LR)
    if -ALL['L'] <= x <= ALL['R'] and -ALL['D'] <= y <= ALL['U']:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()