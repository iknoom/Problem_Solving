N, K = map(int, input().split())

ans = -1
dr = N
M = 10 ** len(str(N))
r = 0

for i in range(K):
    r = (r + dr) % K
    if r == 0:
        ans = i + 1
        break
    dr = (dr * M) % K

print(ans)