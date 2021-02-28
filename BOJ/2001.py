def count_jewels(jewels):
    ret = 0
    for i in range(K):
        if jewels & (1 << i):
            ret += 1
    return ret

def bfs(start, jewels):
    vst[start][jewels] = True
    q = [(start, jewels)]
    if is_jewel[0] >= 0:
        jewels |= (1 << is_jewel[0])
        vst[start][jewels] = True
        q.append((start, jewels))
    for u, jwl in q:
        cur_w = count_jewels(jwl)
        for v, w in adj[u]:
            if cur_w > w:
                continue
            if not vst[v][jwl]:
                vst[v][jwl] = True
                q.append((v, jwl))
            if is_jewel[v] >= 0 and not vst[v][jwl | (1 << is_jewel[v])]:
                vst[v][jwl | (1 << is_jewel[v])] = True
                q.append((v, jwl | (1 << is_jewel[v])))

if __name__ == "__main__":
    # input
    N, M, K = map(int, input().split())
    adj = [[] for _ in range(N)]
    is_jewel = [-1] * N
    for i in range(K):
        j = int(input()) - 1
        is_jewel[j] = i
    for _ in range(M):
        u, v, w = map(int, input().split())
        adj[u - 1].append((v - 1, w))
        adj[v - 1].append((u - 1, w))

    # solution
    vst = [[False] * (1 << K) for _ in range(N)]
    bfs(0, 0)
    print(max(count_jewels(i) for i in range(1 << K) if vst[0][i]))