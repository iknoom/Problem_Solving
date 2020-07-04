def make_fact(n):
    fact = [1, 1]
    for i in range(2, n + 1):
        fact.append((fact[-1] * i))
    return fact

fact = make_fact(300)
ans = []
N, M, K = map(int, input().split())
an = N
zn = M
MAX = (fact[N + M] // fact[N]) // fact[M]

if K > MAX:
    print(-1)
    exit()

for i in range(N + M):
    if K == 1:
        if an:
            ans.append('a')
            an -= 1
        else:
            ans.append('z')
        continue
    n = N + M - i - 1
    k = zn
    combination = (fact[n] // fact[n - k]) // fact[k]
    if combination >= K:
        ans.append('a')
        an -= 1
    else:
        K -= combination
        ans.append('z')
        zn -= 1

print(''.join(ans))
