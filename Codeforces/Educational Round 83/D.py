n, m = map(int, input().split())
if n == 2:
    print(0)
    exit()

mod = 998244353
def cb(n, k):
    global mod
    ret = a = b = 1
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
    global mod
    ret = 1
    two = 2
    while n:
        if n & 1:
            n -= 1
            ret *= two
            ret %= mod
        two *= two
        two %= mod
        n //= 2
    return ret

ans = cb(m, n - 1)
ans *= two_pow(n - 3)
ans %= mod

ans *= n - 2
ans %= mod

print(ans)

