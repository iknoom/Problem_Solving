import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    B = []
    for i in range(N):
        if A[i] < 0:
            for d in [-1, 1]:
                x = i + d
                if 0 <= x < N and A[x] >= 0:
                    B.append(A[x])
    if not B:
        print(0 , 0)
    else:
        x , y = max(B), min(B)
        m = (x + y)//2
        diff = 0
        for i in range(N):
            if A[i] < 0:
                A[i] = m
        for i in range(N-1):
            diff = max(diff, abs(A[i+1] - A[i]))
        print(diff, m)