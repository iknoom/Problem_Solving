N = int(input())
A = list(map(int, input().split()))
k = (1 << 31)
X = -1
while k:
    T = []
    for i in range(N):
        if A[i] & k:
            T.append(i)

    if len(T) == 1:
        X = T[0]
        break

    else:
        k >>= 1

if X < 0:
    print(*A)

else:
    ret = A[X]
    A.pop(X)
    print(ret, *A)


