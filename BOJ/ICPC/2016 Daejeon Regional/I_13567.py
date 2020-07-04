M, n = map(int, input().split())
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
x = y = i = 0
flag = False
for _ in range(n):
    t, d = input().split()
    d = int(d)
    if t == "MOVE":
        x += dx[i] * d
        y += dy[i] * d
    else:
        if d == 0: d = 1
        else: d = -1
        i = (i + d) % 4
    if 0 <= x <= M and 0 <= y <= M: continue
    flag = True
if flag:
    print(-1)
else:
    print(x, y)