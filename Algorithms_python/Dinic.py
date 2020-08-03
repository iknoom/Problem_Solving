INF = 10**9
N = 0
capacity = list()
flow = list()
level = list()
work = list()

def bfs():
    global N, capacity, flow, level
    level = [-1] * (N + 2)
    level[S] = 0
    queue = [S]
    for u in queue:
        for v in range(N + 2):
            if level[v] < 0 and capacity[u][v] - flow[u][v] > 0:
                level[v] = level[u] + 1
                queue.append(v)
    return level[E] != -1

def dfs(cur, dst, flow_i):
    global N, capacity, flow, level, work
    if cur == dst:
        return flow_i
    while work[cur] < N + 2:
        nxt = work[cur]
        if level[nxt] == level[cur] + 1 and capacity[cur][nxt] - flow[cur][nxt] > 0:
            df = dfs(nxt, dst, min(capacity[cur][nxt] - flow[cur][nxt], flow_i))
            if df > 0:
                flow[cur][nxt] += df
                flow[nxt][cur] -= df
                return df
        work[cur] += 1
    return 0

if __name__ == '__main__':
    N = int(input())
    team = list(map(int, input().split()))
    capacity = [list(map(int, input().split())) + [0, 0] for _ in range(N)]
    capacity += [[0] * (N * 2) for _ in range(2)]
    flow = [[0] * (N + 2) for _ in range(N + 2)]
    level = [-1] * (N + 2)
    work = [0] * (N + 2)
    S, E = N, N + 1

    for i in range(N):
        if team[i] == 1: capacity[S][i] = INF
        if team[i] == 2: capacity[i][E] = INF

    total = 0
    while bfs():
        work = [0] * (N + 2)
        while True:
            flow_i = dfs(S, E, INF)
            if not flow_i: break
            total += flow_i

    vst = [False] * (N + 2)
    vst[S] = True
    queue = [S]
    for u in queue:
        for v in range(N + 2):
            if not vst[v] and capacity[u][v] - flow[u][v] > 0:
                vst[v] = True
                queue.append(v)
    A = [i + 1 for i in range(N) if vst[i]]
    B = [i + 1 for i in range(N) if not vst[i]]

    print(total)
    print(*A)
    print(*B)
