N = int(input())
team = list(map(int, input().split()))
c = [list(map(int, input().split())) + [0, 0] for _ in range(N)]
c += [[0] * (N * 2) for _ in range(2)]
f = [[0] * (N + 2) for _ in range(N + 2)]
level = [-1] * (N + 2)
work = [0] * (N + 2)
S, E = N, N + 1
INF = 10**9

def bfs():
    global level
    level = [-1] * (N + 2)
    level[S] = 0
    queue = [S]
    for u in queue:
        for v in range(N + 2):
            if level[v] < 0 and c[u][v] - f[u][v] > 0:
                level[v] = level[u] + 1
                queue.append(v)
    return level[E] != -1

def dfs(cur, dst, flow):
    global work, f
    if cur == dst:
        return flow
    while work[cur] < N + 2:
        nxt = work[cur]
        if level[nxt] == level[cur] + 1 and c[cur][nxt] - f[cur][nxt] > 0:
            df = dfs(nxt, dst, min(c[cur][nxt] - f[cur][nxt], flow))
            if df > 0:
                f[cur][nxt] += df
                f[nxt][cur] -= df
                return df
        work[cur] += 1
    return 0

if __name__ == '__main__':
    for i in range(N):
        if team[i] == 1: c[S][i] = INF
        if team[i] == 2: c[i][E] = INF
    total = 0
    while bfs():
        work = [0] * (N + 2)
        while True:
            flow = dfs(S, E, INF)
            if not flow: break
            total += flow

    vst = [False] * (N + 2)
    vst[S] = True
    queue = [S]
    for u in queue:
        for v in range(N + 2):
            if not vst[v] and c[u][v] - f[u][v] > 0:
                vst[v] = True
                queue.append(v)
    A = [i + 1 for i in range(N) if vst[i]]
    B = [i + 1 for i in range(N) if not vst[i]]

    print(total)
    print(*A)
    print(*B)
