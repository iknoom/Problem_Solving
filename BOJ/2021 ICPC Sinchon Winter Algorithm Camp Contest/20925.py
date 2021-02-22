INF = float('inf')

if __name__ == "__main__":
    # input
    N, T = map(int, input().split())
    c = []
    e = []
    for _ in range(N):
        c_i, e_i = map(int, input().split())
        c.append(c_i)
        e.append(e_i)
    dist = [list(map(int, input().split())) for _ in range(N)]

    # solution
    exp = [[-INF] * N for _ in range(T + 1)]
    for i in range(N):
        if c[i] == 0:
            exp[0][i] = 0
    for t in range(T):
        for i in range(N):
            for j in range(N):
                before = t - dist[i][j]
                if before >= 0 and exp[before][i] >= c[j]:
                    exp[t][j] = max(exp[t][j], exp[before][i])
        for i in range(N):
            exp[t + 1][i] = exp[t][i] + e[i]
    print(max(exp[T]))