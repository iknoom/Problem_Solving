N, M = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(N)]
vst = [[False] * M for _ in range(N)]
dx = [1, 1, 1, 0 ,-1, -1, -1, 0]
dy = [1, 0, -1, -1, -1, 0, 1, 1]
ans = 0

def bfs(i, j):
    q = [(i, j)]
    vst[j][i] = True
    flag = True
    for x, y in q:
        for k in range(8):
            xx, yy = x + dx[k], y + dy[k]
            if 0 <= xx < M and 0 <= yy < N:
                if B[y][x] < B[yy][xx]:
                    flag = False
                if B[y][x] == B[yy][xx] and not vst[yy][xx]:
                    vst[yy][xx] = True
                    q.append((xx, yy))
    return flag

for i in range(M):
    for j in range(N):
        if vst[j][i] or B[j][i] == 0:
            continue
        if bfs(i, j):
            ans += 1
print(ans)