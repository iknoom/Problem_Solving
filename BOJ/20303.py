def bfs(s):
    vst[s] = True
    queue = [s]
    candy = 0
    count = 0
    for u in queue:
        candy += C[u]
        count += 1
        for v in adj[u]:
            if not vst[v]:
                queue.append(v)
                vst[v] = True
    return (count, candy)

if __name__ == "__main__":
    N, M, K = map(int, input().split())
    C = list(map(int, input().split()))
    adj = [list() for _ in range(N)]
    vst = [False] * N
    for _ in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    knapsack = []
    for s in range(N):
        if not vst[s]:
            knapsack.append(bfs(s))

    dp = [[0] * K for _ in range(2)]
    a = 0
    for count, candy in knapsack:
        b = 1 - a
        for i in range(K):
            dp[b][i] = dp[a][i]
            if i >= count:
                dp[b][i] = max(dp[b][i], dp[a][i - count] + candy)
        a = 1 - a
    print(max(dp[a]))