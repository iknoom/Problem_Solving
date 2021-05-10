A = sorted(map(int, input().split()))
d1 = A[1] - A[0]
d2 = A[2] - A[1]
if d1 == d2:
    print(A[2] + d1)
elif d2 * 2 == d1:
    print(A[0] + d2)
else:
    print(A[1] + d1)
