import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10**9 + 7

pos = []
nag = []
pn = []
zero = 0

for i in range(N):
    if A[i] > 0:
        pos.append(A[i])
        pn.append((A[i], True))
    elif A[i] < 0:
        nag.append(A[i])
        pn.append((-A[i], False))
    else:
        zero += 1

pos.sort()
nag.sort(reverse=True)
pn.sort()

# hard case work
if N - zero < K:
    print(0)

elif N == K:
    ans = 1
    for i in range(K):
        ans *= A[i]
        ans %= MOD
    print(ans)

elif N - zero == K:
    ans = 1
    if len(nag) & 1 == 0:
        for k in nag + pos:
            ans *= k
            ans %= MOD
    else:
        ans = 0
    print(ans)

elif not pos and zero > 0:
    print(0)

elif not pos:
    ans = 1
    if K & 1:
        for i in range(K):
            ans *= nag[i]
            ans %= MOD
    else:
        for i in range(K):
            ans *= nag[-i-1]
            ans %= MOD
    print(ans)

elif len(pos) == K - 1:
    pos =

# nagative and positive
else:
    # large first
    arr = []

    for i in range(K):
        if not pos: break
        arr.append(pos.pop())

    while len(arr) < K:
        arr.append(1)

    ans = 1

    while arr:
        if len(arr) == 1:
            ans *= arr[0]
            ans %= MOD
            break

        a = arr.pop()
        b = arr.pop()
        if len(nag) < 2:
            ans *= a * b
            ans %= MOD
        else:
            x = nag.pop()
            y = nag.pop()
            ans *= max(x * y, a * b)
            ans %= MOD

    print(ans)
