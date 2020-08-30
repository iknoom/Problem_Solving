import sys

input = sys.stdin.readline

def solution():
    N = int(input())
    A = list(map(int, input().split()))

    if N == 1:
        print(1, 1)
        print(-A[0])
        print(1, 1)
        print(0)
        print(1, 1)
        print(0)
        return

    print(1, N - 1)
    for i in range(N - 1):
        print((N - 1) * A[i], end=' ')
        A[i] += (N - 1) * A[i]
    print()

    print(N, N)
    print(-A[-1])
    A[-1] = 0

    print(1, N)
    for i in range(N):
        print(-A[i], end=' ')
    print()

if __name__ == "__main__":
    solution()