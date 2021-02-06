import sys
input = sys.stdin.readline

def make_flow(prv):
    ret = 10**9
    cur = 1
    while cur != 0:
        ret = min(ret, c[prv[cur]][cur] - f[prv[cur]][cur])
        cur = prv[cur]
    cur = 1
    while cur != 0:
        f[prv[cur]][cur] += ret
        f[cur][prv[cur]] -= ret
        cur = prv[cur]
    return ret

def bfs():
    global N
    prv = [-1] * N
    q = [0]
    for u in q:
        for v in adj[u]:
            if c[u][v] - f[u][v] > 0 and prv[v] < 0:
                prv[v] = u
                q.append(v)
                if v == 1: return make_flow(prv)
    return -1

if __name__ == "__main__":
    N, P = map(int, input().split())
    f = [[[0] * N for _ in range(N)] for _ in range(2)]
    c = [[[0] * N for _ in range(N)] for _ in range(2)]
    adj = [[] for _ in range(N)]

    for _ in range(P):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        adj[u].append(v)
        adj[v].append(u)
        c[u][v] += 1

    ans = 0
    while True:
        ret = bfs()
        if ret < 0: break
        ans += ret
    print(ans)