from sys import stdin
input = stdin.readline
INF = float('inf')

def bfs(start):
    level[start] = 0
    queue = [start]
    for u in queue:
        for v, c in adj[u]:
            if level[v] < 0:
                level[v] = level[u] + 1
                adj2[v].append((u, c))
                queue.append(v)
            elif level[v] == level[u] + 1:
                adj2[v].append((u, c))

def forward(start):
    ret = []
    queue = {start}
    while True:
        next_queue = set()
        min_c = INF
        for u in queue:
            for v, c in adj2[u]:
                if min_c > c:
                    next_queue = {v}
                    min_c = c
                elif min_c == c:
                    next_queue.add(v)
        if min_c == INF:
            return ret
        ret.append(min_c)
        queue = next_queue


if __name__ == '__main__':
    N, M = map(int, input().split())
    adj = [[] for _ in range(N)]
    adj2 = [[] for _ in range(N)]
    level = [-1] * N
    for _ in range(M):
        u, v, c = map(int, input().split())
        adj[u - 1].append((v - 1, c))
        adj[v - 1].append((u - 1, c))
    bfs(N - 1)
    answer = forward(0)
    print(len(answer))
    print(*answer)