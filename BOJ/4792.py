from sys import stdin
input = stdin.readline
INF = float('inf')

def find(p, u):
    if p[u] != u:
        p[u] = find(p, p[u])
    return p[u]

def kruskal(n, edges):
    ret = 0
    vcnt = 0
    p = [i for i in range(n)]
    for rb, u, v in edges:
        u = find(p, u)
        v = find(p, v)
        if u == v:
            continue
        p[u] = v
        vcnt += 1
        ret += rb
        if vcnt == n - 1:
            return ret
    return INF

def solution(n, m, k):
    edges = []
    for _ in range(m):
        c_str, f_str, t_str = input().split()
        c = 1 if c_str == 'B' else 0
        f = int(f_str) - 1
        t = int(t_str) - 1
        edges.append((c, f, t))
    min_k = kruskal(n, sorted(edges))
    max_k = kruskal(n, sorted(edges, reverse=True))
    if min_k <= k <= max_k:
        print(1)
    else:
        print(0)

if __name__ == '__main__':
    while True:
        n, m, k = map(int, input().split())
        if n + m + k == 0:
            break
        solution(n, m, k)