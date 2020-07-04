import sys
input = sys.stdin.readline

def is_overlap(a1, b1, a2, b2):
    if a1 > b1: a1, b1 = b1, a1
    if a2 > b2: a2, b2 = b2, a2

    if b1 < a2 or b2 < a1: return 0
    elif b1 == a2 or b2 == a1: return 1
    else: return 4

def is_cross(a, b, T):
    if a > b: a, b = b, a
    ret = 0
    for t in T:
        if a <= t <= b: ret += 1
    return ret

T = int(input())

for _ in range(T):
    xmin, ymin, xmax, ymax = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    y_side = [(xmin, ymin, ymax), (xmax, ymin, ymax)]
    x_side = [(ymin, xmin, xmax), (ymax, xmin, xmax)]

    ans = 0
    if x1 == x2:
        if x1 in [xmin, xmax]: print(is_overlap(y1, y2, ymin, ymax))
        elif xmin < x1 < xmax: print(is_cross(y1, y2, [ymin, ymax]))
        else: print(0)
        continue

    if y1 == y2:
        if y1 in [ymin, ymax]: print(is_overlap(x1, x2, xmin, xmax))
        elif ymin < y1 < ymax: print(is_cross(x1, x2, [xmin, xmax]))
        else: print(0)
        continue

    for x0, Ly, Ry in y_side:
        if x0 < min(x1, x2) or max(x1, x2) < x0: continue
        y0 = (y2 - y1) * (x0 - x1) / (x2 - x1) + y1
        if Ly < y0 < Ry: ans += 1

    for y0, Lx, Rx in x_side:
        if y0 < min(y1, y2) or max(y1, y2) < y0: continue
        x0 = (x2 - x1) * (y0 - y1) / (y2 - y1) + x1
        if Lx <= x0 <= Rx: ans += 1

    print(ans)

