def cb(n, k):
    ret = a = b = 1
    mod = 10**9 + 7
    for i in range(k):
        a *= n-i
        a %= mod
        b *= i + 1
        b %= mod
    m = mod-2
    while m > 0:
        if m % 2 != 0:
            ret *= b
            ret %= mod
        b *= b
        b %= mod
        m //= 2
    ret *= a
    ret %= mod
    return ret

def two_pow(n):
    ret = 1
    two = 2
    mod = 10 ** 9 + 7
    while n:
        if n & 1:
            n -= 1
            ret *= two
            ret %= mod
        two *= two
        two %= mod
        n //= 2
    return ret

if __name__ == "__main__":
    N, a, b = map(int, input().split())
    mod = 10 ** 9 + 7
    print((two_pow(N) - 1 - cb(N, a) - cb(N, b)) % mod)