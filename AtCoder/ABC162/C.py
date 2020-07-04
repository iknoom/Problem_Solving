K = int(input())
ans = 0

dp = {}

def gcd(x, y):
    if x < y: x, y = y, x
    while y:
        n = x%y
        x = y
        y = n
    return x

for i in range(1, K + 1):
    for j in range(1, K + 1):
        for k in range(1, K + 1):
            a, b, c = sorted([i, j, k])
            if (a, b, c) in dp:
                ans += dp[(a, b, c)]
            else:
                ret = gcd(a, b)
                ans += gcd(ret, c)

print(ans)