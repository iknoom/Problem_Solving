import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))

S = sum(A)

if N < S:
    print(-1)
else:
    print(N - S)