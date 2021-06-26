from sys import setrecursionlimit, stdin
input = stdin.readline
setrecursionlimit(5000)

def find(p, u):
    if p[u] == u:
        return u
    p[u] = find(p, p[u])
    return p[u]


def union(p, u, v):
    u = find(p, u)
    v = find(p, v)
    if u != v:
        p[u] = v


def sol(N, arr):
    p = [i for i in range(N)]
    for i in range(N - 1):
        for j in range(i + 1, N):
            x1, y1, r1 = arr[i]
            x2, y2, r2 = arr[j]
            if abs(x1 - x2) ** 2 + abs(y1 - y2) ** 2 <= (r1 + r2) ** 2:
                union(p, i, j)
    return len(set(find(p, u) for u in range(N)))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        arr = [tuple(map(int, input().split())) for _ in range(N)]
        answer = sol(N, arr)
        print(answer)