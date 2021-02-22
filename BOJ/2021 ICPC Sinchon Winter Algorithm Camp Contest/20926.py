from heapq import *
ROCK = -1
HOLE = -2
INF = float('inf')
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def is_ok(x, y):
    return (0 <= x < W and 0 <= y < H)

def forward(i, x1, y1):
    d = 0
    while is_ok(x1 + dx[i], y1 + dy[i]):
        if delay[y1 + dy[i]][x1 + dx[i]] == HOLE:
            return -1, -1, -1
        if delay[y1 + dy[i]][x1 + dx[i]] == ROCK:
            return d, x1, y1
        x1 += dx[i]
        y1 += dy[i]
        d += delay[y1][x1]
        if x1 == Ex and y1 == Ey:
            return d, x1, y1
    return -1, -1, -1

def dijkstra():
    dist = [[INF] * W for _ in range(H)]
    dist[Sy][Sx] = 0
    pq = [(0, Sx, Sy)]
    while pq:
        d, x, y = heappop(pq)
        if x == Ex and y == Ey:
            return d
        for i in range(4):
            diff, x1, y1 = forward(i, x, y)
            if diff < 0:
                continue
            d1 = d + diff
            if dist[y1][x1] > d1:
                dist[y1][x1] = d1
                heappush(pq, (d1, x1, y1))
    return -1

if __name__ == "__main__":
    # input
    W, H = map(int, input().split())
    delay = [[0] * W for _ in range(H)]
    Sx, Sy = -1, -1
    Ex, Ey = -1, -1
    for y in range(H):
        for x, value in enumerate(input()):
            if value == 'R':
                delay[y][x] = ROCK
            elif value == 'H':
                delay[y][x] = HOLE
            elif value == 'T':
                Sx, Sy = x, y
            elif value == 'E':
                Ex, Ey = x, y
            else:
                delay[y][x] = int(value)
    # solution
    answer = dijkstra()
    print(answer)