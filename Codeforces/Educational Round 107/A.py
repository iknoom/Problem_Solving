from sys import stdin
input = stdin.readline


def solution():
    N = int(input())
    R = list(map(int, input().split()))
    print(sum(r in [1, 3] for r in R))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()