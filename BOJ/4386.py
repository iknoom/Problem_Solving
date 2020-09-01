from math import sqrt

def find(u):
    if p[u] != u: p[u] = find(p[u])
    return p[u]

if __name__ == "__main__":
    n = int(input())
    points = [tuple(map(float, input().split())) for _ in range(n)]
    p = [i for i in range(n)]
    edges = []
    for i in range(n):
        for j in range(n):
            if i != j:
                dx = points[i][0] - points[j][0]
                dy = points[i][1] - points[j][1]
                dist = sqrt(dx * dx + dy * dy)
                edges.append((dist, i, j))
    edges.sort()
    ans = 0.0
    for dist, u, v in edges:
        if find(u) == find(v):
            continue
        p[find(u)] = p[find(v)]
        ans += dist
    print(ans)