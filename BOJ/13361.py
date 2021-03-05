from collections import defaultdict
from sys import stdin
input = stdin.readline

def bfs_fringe(s):
    outer = 0
    inner = 0
    q = [s]
    for u in q:
        inner = max(inner + cost[u], outer + cost[u] + additional_cost[u])
        outer += cost[u]
        cost[u] = 0
        additional_cost[u] = 0
        for v in adj[u]:
            if count[v] == 0:
                continue
            outer += v
            inner += u
            count[v] -= 1
            count[u] -= 1
            if count[v] == 1:
                q.append(v)
            else:
                cost[v] += outer
                additional_cost[v] = max(additional_cost[v], inner - outer)
                return

if __name__ == "__main__":
    # input
    N = int(input())
    adj = defaultdict(list)
    count = defaultdict(int)
    cost = defaultdict(int)
    additional_cost = defaultdict(int)
    for _ in range(N):
        s, t = map(int, input().split())
        adj[s].append(t)
        adj[t].append(s)
        count[s] += 1
        count[t] += 1

    # count == 1
    for k, v in count.items():
        if v == 1:
            bfs_fringe(k)
    # count == 2
    for k, v in count.items():
        if v == 2:
            cost[k] += k
            additional_cost[k] = 0
    # print answer
    print(sum(cost.values()) + sum(additional_cost.values()))