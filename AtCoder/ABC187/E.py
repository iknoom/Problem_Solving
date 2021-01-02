from sys import stdin

input = stdin.readline

def fill_level():
    q = [(0, 0)]
    vst = [False] * N
    vst[0] = True
    for u, l in q:
        level[u] = l
        for v in adj[u]:
            if vst[v]: continue
            vst[v] = True
            q.append((v, l + 1))

def BFS():
    q = [(0, 0)]
    vst = [False] * N
    vst[0] = True
    for u, d in q:
        diff[u] += d
        d = diff[u]
        for v in adj[u]:
            if vst[v]: continue
            vst[v] = True
            q.append((v, d))

if __name__ == "__main__":
    N = int(input())
    level = [-1] * N
    adj = [[] for _ in range(N)]
    edges = []
    for _ in range(N - 1):
        a, b = map(int, input().split())
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
        edges.append((a - 1, b - 1))
    fill_level()

    diff = [0] * N

    Q = int(input())
    for _ in range(Q):
        t, e, x = map(int, input().split())
        a, b = edges[e - 1]
        if t == 1:
            # a
            if level[a] < level[b]:
                diff[0] += x
                diff[b] -= x
            else:
                diff[a] += x
        else:
            # b
            if level[b] < level[a]:
                diff[0] += x
                diff[a] -= x
            else:
                diff[b] += x
    BFS()
    print(*diff, sep='\n')