from sys import stdin
input = stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(input().rstrip())
    B = list(input().rstrip())
    Wcnt = 0
    Bcnt = 0
    for i in range(N):
        if A[i] == B[i]:
            continue
        if A[i] == 'W':
            Bcnt += 1
        else:
            Wcnt += 1
    print(max(Wcnt, Bcnt))