from sys import stdin, setrecursionlimit
setrecursionlimit(1005)
input = stdin.readline

def find(u, p):
    if p[u] == u:
        return u
    p[u] = find(p[u], p)
    return p[u]

def union(u, v, p):
    a = find(u, p)
    b = find(v, p)
    if a != b:
        p[a] = b
        return True
    return False

n, m1, m2 = map(int, input().split())
Ap = list(range(n))
Bp = list(range(n))
for _ in range(m1):
    u, v = map(int, input().split())
    union(u - 1, v - 1, Ap)
for _ in range(m2):
    u, v = map(int, input().split())
    union(u - 1, v - 1, Bp)

answer = []

for i in range(n - 1):
    for j in range(i + 1, n):
        if find(i, Ap) != find(j, Ap) and find(i, Bp) != find(j, Bp):
            union(i, j, Ap)
            union(i, j, Bp)
            answer.append((i + 1, j + 1))

print(len(answer))
for a, b in answer:
    print(a, b)