from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(200001)

def find(p, u):
    if p[u] == u:
        return u
    p[u] = find(p, p[u])
    return p[u]

def union(p, u, v):
    u = find(p, u)
    v = find(p, v)
    if u == v:
        return False
    p[u] = v
    return True

if __name__ == "__main__":
    # input
    N, Q = map(int, input().split())
    x_sweep = []
    y_sweep = []
    for i in range(N):
        x0, y0, x1, y1 = map(int, input().split())
        if x0 > x1:
            x0, x1 = x1, x0
        if y0 > y1:
            y0, y1 = y1, x0
        x_sweep.append((x0, x1, i))
        y_sweep.append((y0, y1, i))

    # Sweeping & Union-Find
    x_sweep.sort()
    y_sweep.sort()
    p = [i for i in range(N)]
    for sweep in [x_sweep, y_sweep]:
        before = -1
        end_point = -1
        for s, e, i in sweep:
            if before < 0 or end_point < s:
                before = i
                end_point = e
            else:
                union(p, i, before)
                end_point = max(end_point, e)

    # Query
    for _ in range(Q):
        u, v = map(int, input().split())
        print(int(find(p, u - 1) == find(p, v - 1)))