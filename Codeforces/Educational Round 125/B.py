import sys

input = sys.stdin.readline


def solution():
    n, B, x, y = map(int, input().split())
    S = 0
    c = 0
    for _ in range(n):
        if c + x > B:
            c -= y
        else:
            c += x
        S += c
    print(S)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()