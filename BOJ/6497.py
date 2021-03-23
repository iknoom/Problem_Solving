from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(10**9)


def find(p, u):
    if p[u] == u:
        return u
    p[u] = find(p, p[u])
    return p[u]


def union(p, x, y):
    x = find(p, x)
    y = find(p, y)
    if x == y:
        return True
    p[x] = y
    return False


def solution(m, n, edges):
    p = [i for i in range(m)]
    edges.sort(key=lambda x: x[2])
    S = 0
    for x, y, z in edges:
        if union(p, x, y):
            S += z
    return S


def main():
    while True:
        m, n = map(int, input().split())
        if m + n == 0:
            return
        edges = [tuple(map(int, input().split())) for _ in range(n)]
        answer = solution(m, n, edges)
        print(answer)


if __name__ == '__main__':
    main()