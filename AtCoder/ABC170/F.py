import sys
input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
POND = [input().rstrip() for _ in range(H)]
vst = [[0] * W for _ in range(H)]
x1 -= 1; y1 -= 1
x2 -= 1; y2 -= 1

q = [(x1, y1)]
vst[x1][y1] = 1

for x0, y0 in q:
    for i in range(4):
        for d in range(1, K + 1):
            xx, yy = x0 + d * dx[i], y0 + d * dy[i]
            if 0 <= xx < H and 0 <= yy < W:
                if POND[xx][yy] == '@': break
                if POND[xx][yy] == '.' and vst[xx][yy] == 0:
                    vst[xx][yy] = vst[x0][y0] + 1
                    q.append((xx, yy))

if vst[x2][y2] == 0:
    print(-1)
else:
    print(vst[x2][y2] - 1)