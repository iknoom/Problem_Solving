# 다음 세 가지 조건을 만족하면서 N개의 마을 중 몇 개의 마을을 '우수 마을'로 선정하려고 한다.
# 1. '우수 마을'로 선정된 마을 주민 수의 총 합을 최대로 해야 한다.
# 2. 즉 '우수 마을'끼리는 서로 인접해 있을 수 없다.
# 3. '우수 마을'로 선정되지 못한 마을은 적어도 하나의 '우수 마을'과는 인접해 있어야 한다.

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
        dp2[u] += max(dp1[v], dp2[v])

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

    vst = [False] * N
    dfs(0)
    print(max(dp1[0], dp2[0]))