N = int(input())
A = [int(input()) for _ in range(N)]
B = sorted(A)
print(sum(A[i] != B[i] for i in range(N))-1)
