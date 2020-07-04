N, M, B = map(int, input().split())
MAP = [list(map(int,input().split())) for _ in range(N)]
ans = 10**9
min_h = -1
for H in range(257):
    cur = 0
    block = B
    for i in range(N):
        for j in range(M):
            diff = MAP[i][j] - H
            if MAP[i][j] < H: cur += (-diff)
            else: cur += 2 * diff
            block += diff
    if block < 0: continue
    if ans >= cur:
        ans = cur
        min_h = H
print(ans, min_h)