dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N = int(input())
color = [[0] * 102 for _ in range(102)]
for _ in range(N):
    x, y = map(int, input().split())
    for j in range(10):
        for i in range(10):
            color[y + j][x + i] = 1

L = 0
for y in range(1, 101):
    for x in range(1, 101):
        if not color[y][x]:
            continue
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            L += 1 - color[y1][x1]
print(L)