# boj 5615

import sys
input = sys.stdin.readline
a = [2, 3, 5, 7, 11]

def powmod(a, d, n):
    ret = 1
    while d:
        if d & 1:
            ret *= a; ret %= n
        a *= a; a %= n
        d //= 2
    return ret

def miller_rabin(n):
    for a_i in a:
        d = n - 1
        flag = False
        while d & 1 == 0:
            if powmod(a_i, d, n) == n - 1:
                flag = True
            d >>= 1
        x = powmod(a_i, d, n)
        if x == n - 1 or x == 1: flag = True
        if not flag: return False
    return True

ans = 0
for _ in range(int(input())):
    n = int(input())
    if n < 4: ans += 1
    elif miller_rabin(2 * n + 1): ans += 1
print(ans)