N, A, B = map(int, input().split())
Q = N // (A + B)
R = N % (A + B)
if R > A:
    R = A

print(Q * A + R)