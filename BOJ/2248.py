def cb(n, k):
    a = b = 1
    for i in range(k): a *= n - i;b *= i + 1
    return a // b

N, L, I = map(int, input().split())
ans = ''
for k in range(N-1, -1, -1):
    x = sum(cb(k, j) for j in range(L + 1))
    if x >= I:
        ans += '0'
    else:
        ans += '1'
        I -= x
        L -= 1
print(ans)