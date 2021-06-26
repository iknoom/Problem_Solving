from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    # input
    N, M, K = map(int, input().split())
    adj = [[-1] * N for _ in range(N)]
    value = [[-1] * (M + 1) for _ in range(N)]
    for _ in range(K):
        a, b, c = map(int, input().split())
        adj[a - 1][b - 1] = max(adj[a - 1][b - 1], c)
    # solution
    value[0][1] = 0
    for u in range(N):
        for v in range(u + 1, N):
            if adj[u][v] < 0:
                continue
            for i in range(1, M):
                if value[u][i] < 0:
                    continue
                value[v][i + 1] = max(value[v][i + 1], value[u][i] + adj[u][v])
    answer = max(value[N - 1])
    if answer == -1:
        print(0)
    else:
        print(answer)