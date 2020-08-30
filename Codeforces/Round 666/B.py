from math import log
import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    ans = sum(A) - n

    if n <= 2:
        print(A[0] - 1)
        return

    for i in range(2, 1000000):
        if i ** (n - 1) > A[-1] * (n + 1):
            # print(i, i**n)
            break
        S = 0
        t = 1
        for j in range(n):
            S += abs(A[j] - t)
            t *= i
        ans = min(ans, S)
    print(ans)

if __name__ == "__main__":
    solution()