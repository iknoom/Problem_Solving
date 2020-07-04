def CCW(a, b, c):
    op = a[0] * b[1] + b[0] * c[1] + c[0] * a[1]
    op -= a[0] * c[1] + b[0] * a[1] + c[0] * b[1]
    if op == 0: return 0
    elif op > 0: return 1
    else: return -1

x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
P1, P2, P3, P4 = (x1, y1), (x2, y2), (x3, y3), (x4, y4)
ans = 0
if CCW(P1, P2, P3) * CCW(P1, P2, P4) < 0: ans = 1
print(ans)