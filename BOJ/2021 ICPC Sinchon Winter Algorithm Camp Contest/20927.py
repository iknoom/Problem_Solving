from itertools import combinations
from sys import stdin
input = stdin.readline
INF = 10**9

def find(p, u):
    if p[u] == u:
        return u
    p[u] = find(p, p[u])
    return p[u]

if __name__ == "__main__":
    # input
    N, M = map(int, input().split())
    b = list(map(int, input().split()))
    edges = []
    for _ in range(M):
        u, v, w= map(int, input().split())
        edges.append((u - 1, v - 1, w))

    # solution
    min_value = INF
    answer = None
    for selected_edges in combinations(edges, N - 1):
        value = 0
        degree = [0] * N
        p = [i for i in range(N)]
        for u, v, w in selected_edges:
            degree[u] += 1
            degree[v] += 1
            u = find(p, u)
            v = find(p, v)
            if u == v:
                value = INF
                break
            p[u] = v
            value += w
        if value >= min_value:
            continue
        for i in range(N):
            if degree[i] > b[i]:
                value = INF
                break
        if value < min_value:
            min_value = value
            answer = selected_edges

    if N == 1 and M == 0:
        print("YES")
    elif not answer:
        print("NO")
    else:
        print("YES")
        for u, v, _ in answer:
            print(u + 1, v + 1)