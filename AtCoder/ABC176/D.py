import sys
input = sys.stdin.readline

H, W = map(int, input().split())
Cy, Cx = map(int, input().split())
Dy, Dx = map(int, input().split())
Board = [input().rstrip() for _ in range(H)]

Cy -= 1
Cx -= 1
Dy -= 1
Dx -= 1

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
vst = [[-1] * W for _ in range(H)]

def BFS(y, x, C):
    vst[y][x] = C
    q = [(x, y)]
    for x1, y1 in q:
        for i in range(4):
            x2 = x1 + dx[i]
            y2 = y1 + dy[i]
            if 0 <= x2 < W and 0 <= y2 < H and vst[y2][x2] < 0 and Board[y2][x2] == '.':
                vst[y2][x2] = C
                q.append((x2, y2))

count = 0
for i in range(H):
    for j in range(W):
        if vst[i][j] < 0 and Board[i][j] == '.':
            BFS(i, j, count)
            count += 1




adj = [set() for _ in range(count)]
vst_g = [False] * count

for i in range(H):
    for j in range(W):
        if Board[i][j] == '.':
            cur = vst[i][j]
            for x in [-2, -1, 0, 1, 2]:
                for y in [-2, -1, 0, 1, 2]:
                    x1 = x + j
                    y1 = y + i
                    if 0 <= x1 < W and 0 <= y1 < H and Board[y1][x1] == '.':
                        if vst[y1][x1] != cur:
                            adj[cur].add(vst[y1][x1])



vst_g = [-1] * count
vst_g[vst[Cy][Cx]] = 0
q = [vst[Cy][Cx]]


for u in q:
    for v in adj[u]:
        if vst_g[v] < 0:
            vst_g[v] = vst_g[u] + 1
            q.append(v)

print(vst_g[vst[Dy][Dx]])