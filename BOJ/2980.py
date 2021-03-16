N, L = map(int, input().split())
R = [0] * L
G = [0] * L
for _ in range(N):
    d, r, g = map(int, input().split())
    R[d] = r
    G[d] = g

cur = 0
t = 0
while cur < L:
    if not R[cur]:
        cur += 1
    else:
        dt = t % (R[cur] + G[cur])
        if dt >= R[cur]:
            cur += 1
    t += 1
print(t)
