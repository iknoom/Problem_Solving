import sys
from collections import Counter
input = sys.stdin.readline

def powmod(a, d, n):
    ret = 1
    while d:
        if d & 1:
            ret *= a; ret %= n
        a *= a; a %= n
        d //= 2
    return ret

N = int(input())
MOD = 1000000007
X = Counter()
AB = [tuple(map(int, input().split())) for _ in range(N)]
ans = 0
cnt = 0

for a, b in AB:
    cnt += 1
    x = X[-b/a]
    y = cnt - x - 1
    ret = ans - (powmod(2, x, MOD) - 1) * powmod(2, y, MOD)
    ans += ret
    ans %= MOD
    ans += 1
    X[a/b] += 1
    print(ans)
print(ans)