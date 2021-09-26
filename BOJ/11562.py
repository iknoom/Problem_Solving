from sys import stdin
input = stdin.readline
INF = float('inf')

N, M = map(int, input().split())
dist = [[INF] * N for _ in range(N)]
for _ in range(M):
    u, v, t = map(int, input().split())
    u -= 1
    v -= 1
    if t == 0:
        dist[u][v] = 0
        dist[v][u] = 1
    if t == 1:
        dist[u][v] = 0
        dist[v][u] = 0

for i in range(N):
    dist[i][i] = 0

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

Q = int(input())
for _ in range(Q):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    print(dist[u][v])