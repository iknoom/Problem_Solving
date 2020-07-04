N, X, Y = map(int,input().split())

ans = [0] * (N - 1)

for i in range(N - 1):
    vst = [False] * N
    q = [(i, 0)]
    vst[i] = True
    for u, c in q:
        if i < u: ans[c - 1] += 1
        next = [u + 1, u - 1]
        if u == X - 1:
            next.append(Y - 1)
        if u == Y - 1:
            next.append(X - 1)

        for v in next:
            if 0 <= v < N and not vst[v]:
                q.append((v, c + 1))
                vst[v] = True

print(*ans, sep='\n')