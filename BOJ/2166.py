def CCW(a, b, c):
    ret = a[0] * b[1] + b[0] * c[1] + c[0] * a[1]
    ret -= a[0] * c[1] + b[0] * a[1] + c[0] * b[1]
    return ret

ans = 0

N = int(input())
P = [tuple(map(int,input().split())) for _ in range(N)]
for i in range(1, N - 1):
    ans += CCW(P[0], P[i], P[i + 1])
print("%.1f"%(abs(ans)/2))