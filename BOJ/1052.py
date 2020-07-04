N, K = map(int, input().split())
if N <= K:
    print(0)
else:
    X = []
    t = 1 << 30
    while N:
        if N >= t:
            X.append(t)
            N -= t
        t >>= 1
    ans = 0
    while len(X) > K:
        a = X.pop()
        b = X.pop()
        ans += b - a
        X.append(b * 2)
    print(ans)