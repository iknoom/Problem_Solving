import sys
input = sys.stdin.readline

def bfs(i, vst, adj):
    ret = 0
    vst[i] = True
    q = [i]
    for u in q:
        for v in adj[u]:
            if not vst[v]:
                ret += 1
                vst[v] = True
                q.append(v)
    return ret

if __name__ == "__main__":
    N, M = map(int, input().split())
    adj_in = [[] for _ in range(N)]
    adj_out = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        adj_in[a - 1].append(b - 1)
        adj_out[b - 1].append(a - 1)

    ans = 0
    for i in range(N):
        vst = [False] * N
        if bfs(i, vst, adj_in) + bfs(i, vst, adj_out) + 1 == N:
            ans += 1
    print(ans)