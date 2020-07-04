def CCW(a, b, c):
    op = a[0] * b[1] + b[0] * c[1] + c[0] * a[1]
    op -= a[0] * c[1] + b[0] * a[1] + c[0] * b[1]
    if op == 0: return 0
    elif op > 0: return 1
    else: return -1

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
P1, P2 = (x1, y1), (x2, y2)
P3, P4 = (x3, y3), (x4, y4)
A = CCW(P1, P2, P3) * CCW(P1, P2, P4)
B = CCW(P3, P4, P1) * CCW(P3, P4, P2)

if A == B == 0:
    if P1 > P2: P1, P2 = P2, P1
    if P3 > P4: P3, P4 = P4, P3
    if P2 < P3 or P4 < P1: print(0)
    else: print(1)
else:
    if A <= 0 and B <= 0: print(1)
    else: print(0)
