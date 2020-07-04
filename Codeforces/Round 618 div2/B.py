import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    A = sorted(map(int,input().split()))
    print(A[N] - A[N-1])