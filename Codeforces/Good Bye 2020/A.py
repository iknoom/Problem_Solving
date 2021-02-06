import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    X = list(map(int, input().split()))
    S = set()
    for i in range(n - 1):
        for j in range(i + 1, n):
            S.add(X[j] - X[i])
    print(len(S))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()