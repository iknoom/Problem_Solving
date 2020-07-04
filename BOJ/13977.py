import sys
input = sys.stdin.readline

def make_fact(n, mod):
    fact = [1, 1]
    for i in range(2, n + 1):
        fact.append((fact[-1] * i) % mod)
    return fact

def make_factinv(n, mod):
    factinv = [1, 1]
    inv = [0, 1]
    for i in range(2, n + 1):
        inv.append((-inv[mod % i] * (mod // i)) % mod)
        factinv.append((factinv[-1] * inv[-1]) % mod)
    return factinv

M = int(input())
MOD = 10**9 + 7
MAX = 4 * 10**6
fact = make_fact(MAX, MOD)
factinv = make_factinv(MAX, MOD)

for _ in range(M):
    N, K = map(int, input().split())
    print(fact[N] * factinv[N - K] * factinv[K] % MOD)