T = int(input())
for _ in range(T):
    n = int(input())
    P = [tuple(map(int, input().split())) for _ in range(n + 2)]
    vst = [False] * (n + 2)
    vst[0] = True
    q = [0]
    for u in q:
        for v in range(n + 2):
            if not vst[v] and abs(P[u][0] - P[v][0]) + abs(P[u][1] - P[v][1]) <= 1000:
                vst[v] = True
                q.append(v)
    if vst[-1]: print("happy")
    else: print("sad")