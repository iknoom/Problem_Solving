import sys
input = sys.stdin.readline

def make_flow(prv, flow, capacity):
    ret = 10**9
    cur = 1
    while cur != 0:
        ret = min(ret, capacity[prv[cur]][cur] - flow[prv[cur]][cur])
        cur = prv[cur]
    cur = 1
    while cur != 0:
        flow[prv[cur]][cur] += ret
        flow[cur][prv[cur]] -= ret
        cur = prv[cur]
    return ret

def bfs(N, flow, capacity, adj):
    prv = [-1] * N
    q = [0]
    for u in q:
        for v in adj[u]:
            if capacity[u][v] - flow[u][v] > 0 and prv[v] < 0:
                prv[v] = u
                q.append(v)
                if v == 1: return make_flow(prv, flow, capacity)
    return -1

if __name__ == "__main__":
    N, P = map(int, input().split())
    flow = [[0] * N for _ in range(N)]
    capacity = [[0] * N for _ in range(N)]
    adj = [[] for _ in range(N)]

    for _ in range(P):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
        capacity[u][v] += 1

    ans = 0
    while True:
        ret = bfs(N, flow, capacity, adj)
        if ret < 0: break
        ans += ret
    print(ans)