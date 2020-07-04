n, k = map(int, input().split())
A = list(map(int, input().split()))
B = A[:]
B.sort()
MOD = 998244353
M = set(B[-k:])
ans = 1

i = 0
while A[i] not in M:
    i += 1

prv = i

for i in range(prv + 1, n):
    if A[i] in M:
        ans *= i - prv
        ans %= MOD
        prv = i

print(sum(B[-k:]), ans)

