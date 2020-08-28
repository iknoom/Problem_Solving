from sys import stdin
input = stdin.readline

INF = 10 ** 9

if __name__ == "__main__":
    V, E = map(int, input().split())
    dist = [[INF] * V for _ in range(V)]
    for _ in range(E):
        a, b, w = map(int, input().split())
        dist[a - 1][b - 1] = min(dist[a - 1][b - 1], w)
    for i in range(V):
        dist[i][i] = 0

    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    ans = INF
    for i in range(V):
        for j in range(V):
            if i == j: continue
            ans = min(ans, dist[i][j] + dist[j][i])

    if ans == INF:
        print(-1)
    else:
        print(ans)