import sys

input = sys.stdin.readline
INF = 10**9

def solution():
    n = int(input())
    A = list(map(int, input().split()))
    if n <= 3:
        print(A[0])
        return
    DP = [INF] * (n + 1)
    DP[0] = 0
    for i in range(2, n + 1):
        DP[i] = min(DP[i], DP[i - 2] + A[i - 2])
        if i > 2:
            DP[i] = min(DP[i], DP[i - 3] + A[i - 3])
            DP[i] = min(DP[i], DP[i - 3] + A[i - 3] + A[i - 2])
        if i > 3:
            DP[i] = min(DP[i], DP[i - 4] + A[i - 4] + A[i - 3])
    print(min(DP[-1], DP[-2] + A[-1], DP[-3] + A[-1] + A[-2]))


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()