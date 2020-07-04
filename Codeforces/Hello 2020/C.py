from math import factorial

n, m = map(int,input().split())
X = 1
fac_DP = [1] * (n+1)
for k in range(n):
    X *= (k+1)
    X %= m
    fac_DP[k+1] = X
ans = []
q = fac_DP[n]
ans.append(q)
for i in range(2,n+1):
    q = ans[-1]
    pair = n - i + 1
    q += pair * fac_DP[i] * fac_DP[n-i]
    q %= m
    ans.append(q)

print(sum(ans)%m)