h = lambda x: ord(x) - ord('A') if x <= 'Z' else ord(x) - ord('a') + 26
flow = [[0] * 52 for _ in range(52)]
cap = [[0] * 52 for _ in range(52)]
adj = [set() for _ in range(52)]
S = h('A')
T = h('Z')

def make_flow(prv):
    global S, T
    ret = 10**9
    cur = T
    while cur != S:
        ret = min(ret, cap[prv[cur]][cur] - flow[prv[cur]][cur])
        cur = prv[cur]
    cur = T
    while cur != S:
        flow[prv[cur]][cur] += ret
        flow[cur][prv[cur]] -= ret
        cur = prv[cur]
    return ret

def bfs():
    global S, T
    prv = [-1] * 52
    queue = [S]
    for u in queue:
        for v in adj[u]:
            # 방문하지 않은 노드 중에 용량이 남는 노드
            if cap[u][v] > flow[u][v] and prv[v] < 0:
                queue.append(v)
                prv[v] = u
                if v == T: return make_flow(prv)
    return -1

if __name__ == '__main__':
    N = int(input())
    for _ in range(N):
        u, v, c = input().split()
        u, v, c = h(u), h(v), int(c)
        cap[u][v] += c
        cap[v][u] += c
        adj[u].add(v)
        adj[v].add(u)
    max_flow = 0

    while True:
        # 증가 경로를 찾는다.
        ret = bfs()
        if ret > 0: max_flow += ret
        else: break

    print(max_flow)