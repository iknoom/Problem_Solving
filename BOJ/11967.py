from sys import stdin
input = stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N, M = map(int, input().split())

adj = [[[] for _ in range(N + 1)] for _ in range(N + 1)]

for _ in range(M):
    x, y, a, b = map(int, input().split())
    adj[x][y].append((a, b))

answer = 1
vst = [[False] * (N + 1) for _ in range(N + 1)]
light_on = [[False] * (N + 1) for _ in range(N + 1)]
vst[1][1] = True
light_on[1][1] = True
queue = [(1, 1)]
for x, y in queue:
    for a, b in adj[x][y]:
        if light_on[a][b] or vst[a][b]:
            continue
        answer += 1
        light_on[a][b] = True
        for i in range(4):
            nx, ny = a + dx[i], b + dy[i]
            if nx < 1 or nx > N: continue
            if ny < 1 or ny > N: continue
            if vst[nx][ny]:
                vst[a][b] = True
                queue.append((a, b))
                break
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 1 or nx > N: continue
        if ny < 1 or ny > N: continue
        if vst[nx][ny]: continue
        if not light_on[nx][ny]: continue
        vst[nx][ny] = True
        queue.append((nx, ny))

print(answer)