from sys import stdin, setrecursionlimit
setrecursionlimit(200010)
input = stdin.readline

# tree
N = int(input())
# city 1
# he goes to the city with the smallest number among those cities.
# otherwise, he goes to the city he was in just before visiting the current city for the first time.

adj = [[] for _ in range(N)]
for _ in range(N - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

for i in range(N):
    adj[i].sort()


vst = [False] * N
answer = []

def dfs(u):
    vst[u] = True
    answer.append(u + 1)
    flag = False
    for v in adj[u]:
        if vst[v]: continue
        flag = True
        dfs(v)
        answer.append(u + 1)

dfs(0)

print(*answer)