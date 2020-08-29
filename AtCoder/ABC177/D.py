from sys import stdin
input = stdin.readline

def bfs(s):
    q = [s]
    vst[s] = True
    ret = 1
    for u in q:
        for v in adj[u]:
            if not vst[v]:
                vst[v] = True
                q.append(v)
                ret += 1
    return ret


if __name__ == "__main__":
    N, M = map(int, input().split())
    adj = [set() for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        adj[a - 1].add(b - 1)
        adj[b - 1].add(a - 1)
    vst = [False] * N
    ans = 0
    for i in range(N):
        if not vst[i]:
            ans = max(ans, bfs(i))
    print(ans)