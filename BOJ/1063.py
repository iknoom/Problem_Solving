N = 8

dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, 1, -1, -1]

def get_nxt(c, x, y):
    if c == 'R':
        return x + dx[0], y + dy[0]
    if c == 'L':
        return x + dx[1], y + dy[1]
    if c == 'B':
        return x + dx[2], y + dy[2]
    if c == 'T':
        return x + dx[3], y + dy[3]
    if c == 'RT':
        return x + dx[6], y + dy[6]
    if c == 'RB':
        return x + dx[4], y + dy[4]
    if c == 'LT':
        return x + dx[7], y + dy[7]
    if c == 'LB':
        return x + dx[5], y + dy[5]

def is_ok(x, y):
    return 0 <= x < N and 0 <= y < N

def get_xy(c):
    x = ord(c[0]) - ord('A')
    y = N - int(c[1])
    return x, y

def inv_xy(x, y):
    c1 = chr(x + ord('A'))
    c2 = str(N - y)
    return c1 + c2

if __name__ == '__main__':
    king, stone, _Q = input().split()
    Q = int(_Q)
    kx, ky = get_xy(king)
    sx, sy = get_xy(stone)
    for _ in range(Q):
        c = input()
        nx, ny = get_nxt(c, kx, ky)
        if not is_ok(nx, ny):
            continue
        if nx == sx and ny == sy:
            snx, sny = get_nxt(c, sx, sy)
            if not is_ok(snx, sny):
                continue
            kx, ky = nx, ny
            sx, sy = snx, sny
        else:
            kx, ky = nx, ny
    print(inv_xy(kx, ky))
    print(inv_xy(sx, sy))

