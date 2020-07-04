import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int, input().split())
adj = [list(map(int, input().split()))[1:] for _ in range(N)]
B = [-1] * M

def dfs(a):
    vst[a] = True
    for b in adj[a // 2]:
        b -= 1
        if B[b] < 0 or not vst[B[b]] and dfs(B[b]):
            B[b] = a
            return 1
    return 0

ans = 0
for i in range(N * 2):
    vst = [False] * (N * 2)
    ans += dfs(i)

print(ans)