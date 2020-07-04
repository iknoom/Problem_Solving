g = [[0] * 2001 for _ in range(2001)]

def fill(x1, y1, x2, y2, t):
    for y in range(y1, y2):
        for x in range(x1, x2):
            g[y + 1000][x + 1000] = t

for t in [1, 1, 0]:
    x1, y1, x2, y2 = map(int, input().split())
    fill(x1, y1, x2, y2, t)

print(sum(sum(g[i]) for i in range(2001)))