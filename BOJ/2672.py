def get_H(set_y):
    ret = 0
    sweep_y = sorted(set_y)

    now = -1
    count = 0
    for y, t in sweep_y:
        if count == 0: now = y
        count += t
        if count == 0: ret += y - now
    return ret


if __name__ == "__main__":
    N = int(input())
    sweep_x = []
    for i in range(N):
        ldx, ldy, w, h = map(float, input().split())
        sweep_x += [(ldx, 1, ldy, ldy + h), (ldx + w, -1, ldy, ldy + h)]
    sweep_x.sort()

    ans = 0.0
    now, _, ldy, ruy = sweep_x[0]
    set_y = {(ldy, 1), (ruy, -1)}
    for x, t, dy, uy in sweep_x[1:]:
        ans += (x - now) * get_H(set_y)
        if t == 1:
            set_y.add((dy, 1))
            set_y.add((uy, -1))
        else:
            set_y.discard((dy, 1))
            set_y.discard((uy, -1))
        now = x

    ans = round(ans, 2)

    if int(ans * 100) % 100 == 0:
        print(int(ans))
    else:
        print(ans)