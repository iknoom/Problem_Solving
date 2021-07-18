N, A, X, Y = map(int, input().split())
# A+1 = Y
if N < A:
    print(N * X)
else:
    print(A * X + (N - A) * Y)