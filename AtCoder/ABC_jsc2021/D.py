from sys import stdin
input = stdin.readline

def powmod(x, n, mod):
    ret = 1
    while n:
        if n & 1:
            ret *= x; ret %= mod
        x *= x; x %= mod
        n //= 2
    return ret

if __name__ == '__main__':
    MOD = 10**9 + 7
    N, P = map(int, input().split())
    print(powmod(P - 2, N - 1, MOD) * (P - 1) % MOD)