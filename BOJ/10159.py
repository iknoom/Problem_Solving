import sys

input = sys.stdin.readline

N = int(input())
M = int(input())
adj = [[[] for _ in range(N)] for _ in range(2)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[0][u - 1].append(v - 1)
    adj[1][v - 1].append(u - 1)

def bfs(u):
    ret = 0
    vst = [False] * N
    vst[u] = True
    q = [(u, 0), (u, 1)]
    for x, t in q:
        ret += 1
        for y in adj[t][x]:
            if not vst[y]:
                vst[y] = True
                q.append((y, t))
    return ret - 1

for i in range(N):
    print(N - bfs(i))