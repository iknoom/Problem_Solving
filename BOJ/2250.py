from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(10**9)

def dfs(u, n):
    if L[u] >= 0:
        n = dfs(L[u], n)
    n += 1
    order[u] = n
    if R[u] >= 0:
        n = dfs(R[u], n)
    return n

def bfs(u):
    ans = 0
    ans_level = -1
    q = [u]
    level = 1
    while q:
        l = 10 ** 18
        r = -1
        next_q = []
        for v in q:
            l = min(l, order[v])
            r = max(r, order[v])
            if L[v] >= 0: next_q.append(L[v])
            if R[v] >= 0: next_q.append(R[v])
        if (r - l + 1) > ans:
            ans = r - l + 1
            ans_level = level
        q = next_q
        level += 1
    return ans_level, ans


if __name__ == "__main__":
    N = int(input())
    L = [-1] * N
    R = [-1] * N
    order = [0] * N
    COUNT = [0] * N
    for _ in range(N):
        i, l, r = map(int, input().split())
        i -= 1; l -= 1; r -= 1
        L[i] = l
        R[i] = r
        if l >= 0: COUNT[l] += 1
        if r >= 0: COUNT[r] += 1
    root = COUNT.index(0)
    dfs(root, 0)
    level, L = bfs(root)
    print(level, L)