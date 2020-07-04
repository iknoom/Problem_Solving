import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    CUS = [tuple(map(int, input().split())) for _ in range(n)]
    CUS.sort()
    L = m
    R = m
    prv = 0
    ans = True
    for t, l, r in CUS:
        d = t - prv
        L -= d
        R += d
        if R < l or r < L:
            ans = False
            break
        else:
            R = min(R, r)
            L = max(L, l)
            prv = t
    if ans:
        print("YES")
    else:
        print("NO")