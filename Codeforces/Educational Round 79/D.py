import sys
input = sys.stdin.readline
MOD = 998244353

def powmod(a, b, MOD):
    ret = 1
    while b:
        if b & 1:
            ret *= a
            ret %= MOD
            b -= 1
        a *= a
        a %= MOD
        b >>= 1
    return ret

N = int(input())
A = [0] * 1000001
K = [0] * N
prs = []

for i in range(N):
    T = list(map(int,input().split()))
    K[i] = T[0]
    for j in T[1:]: A[j] += 1
    prs.append(T[1:])

ans = 0
for i in range(N):
    for j in prs[i]:
        a, b = A[j], (K[i] * N * N) % MOD
        ret = ( a * (powmod(b, MOD-2, MOD)) ) % MOD
        ans = (ans + ret) % MOD
print(ans)

