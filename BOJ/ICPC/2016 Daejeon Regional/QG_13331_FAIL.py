
def negative():
    N = int(input())
    V, E = map(int, input().split())
    adj = [[] for _ in range(N)]

    for _ in range(E):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)
    V_4 = []
    V_3 = []
    for i in range(N):
        if len(adj[i]) == 2 or not adj[i]: continue
        elif len(adj[i]) == 3: V_3.append(i)
        elif len(adj[i]) == 4: V_4.append(i)
        else: return -1

    for v in V_3 + V_4:
        new = []
        for u in adj[v]:
            prv = v
            while len(adj[u]) == 2:
                for w in adj[u]:
                    if w != u: u, prv = w, u
            new.append(u)
        adj[v] = new[:]

    if len(V_3) == 6 and not V_4:
        cnt = [0] * N
        s = V_3[0]
        for v in adj[s]:
            for u in adj[v]:
                cnt[u] += 1
        x = adj[s][0]
        for y in adj[x]:
            if cnt[y] != 3: return -1
        return 1

    elif len(V_4) == 5 and not V_3:
        for v in V_4:
            for u in adj[v]:
                if u not in V_4: return -1
        return 1

    else:
        return -1

def affirmative():
    N = int(input())


if input() == '-1':
    print(negative())
else:
    print(affirmative())


