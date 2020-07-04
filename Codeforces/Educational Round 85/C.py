import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    A = []
    B = []
    for _ in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)

    diff = [max(0, A[i] - B[i - 1]) for i in range(N)]
    k = [min(A[i], B[i - 1]) for i in range(N)]
    print(sum(diff) + min(k))