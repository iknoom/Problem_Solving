import sys

input = sys.stdin.readline


def solution():
    N = int(input())
    t = N // 4
    if N % 4 != 0:
        t += 1
    print("9" * (N-t) + "8" * t)



if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()