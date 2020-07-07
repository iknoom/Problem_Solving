import sys
from collections import deque
input = sys.stdin.readline

def BFS(start, n, adj):
    visited = set()
    visited.add(start)
    queue = [start]
    ret = []
    for u in queue:
        for v in adj[u]:
            if len(adj[v]) == 1:
                ret.append((v, u))
            if v not in visited:
                visited.add(v)
                queue.append(v)
    return ret

def clear_fringe(n, adj, count):
    dq = deque([i for i in range(n) if count[i] == 1])
    visited = [False] * n
    while dq:
        u = dq.popleft()
        visited[u] = True
        for v in adj[u]:
            if not visited[v]:
                count[v] -= 1
                if count[v] == 1:
                    dq.append(v)

def solution():
    n, m = map(int, input().split())
    adj = [list() for _ in range(n)]
    count = [0] * n

    for _ in range(m):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)
        count[u - 1] += 1
        count[v - 1] += 1

    clear_fringe(n, adj, count)

    answer = []
    for u in range(n):
        if count[u] == 1:
            continue
        elif count[u] == 0:
            if not adj[u]: continue
            answer += BFS(u, n, adj)
        else:
            for v in adj[u]:
                if count[v] == 1:
                    answer.append((u, v))
    return answer

if __name__ == "__main__":
    answer = solution()
    print(len(answer))
    for u, v in sorted(answer):
        # print(u + 1, v + 1)
        sys.stdout.write(f'{u + 1} {v + 1}\n')