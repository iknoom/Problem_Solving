N = int(input())
adj = [input() for _ in range(N)]
answer = -1
for u in range(N):
    cnt = 0
    for v in range(N):
        if u == v:
            continue
        if adj[u][v] == "Y":
            cnt += 1
        else:
            for k in range(N):
                if k in [u, v]:
                    continue
                if adj[u][k] == "Y" and adj[v][k] == "Y":
                    cnt += 1
                    break
    answer = max(answer, cnt)
print(answer)