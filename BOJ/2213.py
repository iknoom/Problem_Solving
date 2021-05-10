from sys import setrecursionlimit
setrecursionlimit(100001)

def dfs(u):
    vst[u] = True
    dp1[u] += P[u]
    for v in list(adj[u]):
        if vst[v]:
            continue
        dfs(v)
        dp1[u] += dp2[v]
        prv1[u].append(v + N)
        if dp1[v] < dp2[v]:
            dp2[u] += dp2[v]
            prv2[u].append(v + N)
        else:
            dp2[u] += dp1[v]
            prv2[u].append(v)

def bfs(u):
    ret = []
    queue = [u]
    for u in queue:
        if u >= N:
            for v in prv2[u - N]:
                queue.append(v)
        else:
            ret.append(u + 1)
            for v in prv1[u]:
                queue.append(v)
    return ret

if __name__ == '__main__':
    # input
    N = int(input())
    P = list(map(int, input().split()))
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    dp1 = [0] * N # u를 포함했을 때 최댓값
    dp2 = [0] * N # u를 포함하지 않을 때 최댓값
    prv1 = [[] for _ in range(N)]
    prv2 = [[] for _ in range(N)]

    vst = [False] * N
    dfs(0)
    answer = []
    if dp1[0] > dp2[0]:
        answer = bfs(0)
    else:
        answer = bfs(N)
    print(max(dp1[0], dp2[0]))
    print(*sorted(answer))