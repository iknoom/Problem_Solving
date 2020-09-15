import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    A = list(map(int, input().split()))
    L = list(map(int, input().split()))
    stack = []
    for i in range(n):
        if L[i] == 0:
            stack.append(A[i])
    stack.sort()
    for i in range(n):
        if L[i] == 0:
            A[i] = stack.pop()
    print(*A)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()