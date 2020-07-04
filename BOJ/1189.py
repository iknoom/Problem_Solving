R, C, K = map(int, input().split())
B = [list(input()) for _ in range(R)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
vst = [[False] * C for _ in range(R)]
ans = 0

def dfs(x, y, cost):
    global ans

    if x == C - 1 and y == 0:
        if cost == K:
            ans += 1
        return

    for i in range(4):
        xx, yy = x + dx[i], y + dy[i]
        if 0 <= xx < C and 0 <= yy < R and not vst[yy][xx] and B[yy][xx] != 'T':
            vst[yy][xx] = True
            dfs(xx, yy, cost + 1)
            vst[yy][xx] = False

vst[R - 1][0] = True
dfs(0, R - 1, 1)
print(ans)