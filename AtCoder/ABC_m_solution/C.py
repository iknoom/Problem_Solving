import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))

for i in range(K, N):
    if A[i - K] < A[i]:
        print("Yes")
    else:
        print("No")