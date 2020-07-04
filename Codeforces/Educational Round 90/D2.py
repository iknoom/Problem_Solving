import sys
input = sys.stdin.readline


T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(N):
        if i % 2 == 0:
           ans += A[i]
    Max = 0

    # even
    prof = 0
    for i in range(0, N + 1, 2):
        if i + 1 >= N:
            break
        prof += A[i + 1] - A[i]
        if prof < 0:
            prof = 0
        Max = max(Max, prof)

    # odd
    prof = 0
    for i in range(1, N + 1, 2):
        if i + 1 >= N:
            break
        prof += A[i] - A[i + 1]
        if prof < 0:
            prof = 0
        Max = max(Max, prof)
    print(ans + Max)