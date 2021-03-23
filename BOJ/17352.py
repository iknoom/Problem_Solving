from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(300001)

def find(p, u):
    if p[u] == u:
        return u
    p[u] = find(p, p[u])
    return p[u]

def union(p, u, v):
    u = find(p, u)
    v = find(p, v)
    p[u] = v

if __name__ == '__main__':
    N = int(input())
    p = [i for i in range(N)]
    for _ in range(N - 2):
        u, v = map(int, input().split())
        union(p, u - 1, v - 1)
    x, y = {find(p, i) for i in range(N)}
    print(x + 1, y + 1)