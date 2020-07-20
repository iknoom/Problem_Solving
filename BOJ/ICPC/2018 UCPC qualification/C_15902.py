MOD = 10 ** 9 + 7

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

def make_DP(L, fact, factinv):
    DP = [1, 1]
    for i in range(2, L):
        tmp = 0
        for j in range(0, i, 2):
            C = fact[i - 1] * factinv[i - 1 - j] * factinv[j]
            tmp += DP[j] * DP[i - 1 - j] * C
            tmp %= MOD
        DP.append(tmp)
    return DP

def input_bits():
    n = int(input())
    blocks = list(map(int, input().split()))
    bits = []
    for block in blocks:
        if block == 2: bits.append(0)
        bits.append(1)
    return bits

def solution():
    L = int(input())
    fact = make_fact(L, MOD)
    factinv = make_factinv(L, MOD)
    DP = make_DP(L, fact, factinv)

    A_bit = input_bits()
    B_bit = input_bits()

    L_sum = 0
    ans = 1
    cut = 0
    for i in range(L):
        if A_bit[i] == B_bit[i]:
            if cut == 0: continue
            ans *= DP[cut] * factinv[cut]
            ans %= MOD
            L_sum += cut
            cut = 0
        else:
            cut += 1
    ans *= fact[L_sum]
    ans %= MOD
    print(L_sum, ans)

if __name__ == "__main__":
    solution()