from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N, M = map(int, input().split())
    H = list(map(int, input().split()))
    adj = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    # solution
    dp = [1] * N
    sweep = [(H[i], i) for i in range(N)]
    sweep.sort(reverse=True)
    for _, u in sweep:
        for v in adj[u]:
            if H[u] < H[v]:
                dp[u] = max(dp[u], dp[v] + 1)
    print(*dp, sep='\n')