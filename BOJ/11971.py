N, M = map(int, input().split())
limit = []
cur = 0
for _ in range(N):
    l, v = map(int, input().split())
    limit.append((cur, cur + l, v))
    cur += l

hyun = []
cur = 0
for _ in range(M):
    l, v = map(int, input().split())
    hyun.append((cur, cur + l, v))
    cur += l

answer = 0
for i in range(N):
    for j in range(M):
        l, r, v = limit[i]
        hl, hr, hv = hyun[j]
        if hr <= l or r <= hl:
            continue
        answer = max(answer, hv - v)
print(answer)