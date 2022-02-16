import sys

input = sys.stdin.readline


def solution():
    S = input().rstrip()
    E = 0
    N = 0
    for k in S:
        if k == 'E':
            E += 1
        else:
            N += 1
    if N == 1:
        print("NO")
    else:
        print("YES")

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()