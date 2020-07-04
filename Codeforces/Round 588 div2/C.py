from itertools import product

n, m = map(int, input().split())
node = [0, 1, 2, 3, 4, 5, 6]
node = node[:n]
g = []
for _ in range(m):
    a, b = map(int, input().split())
    g.append((a - 1, b - 1))

ans = 0
for pp in product(node, repeat=n):
    D = [[False] * 7 for _ in range(7)]
    for i in range(7):
        D[6][i] = D[i][6] = True
    cnt = 0
    cnt2 = 0
    h = -1
    if 6 in pp:
        h = pp.index(6)
    for a, b in g:
        if a == h or b == h:
            cnt2 += 1
        if not D[pp[a]][pp[b]]:
            D[pp[a]][pp[b]] = True
            D[pp[b]][pp[a]] = True
            cnt += 1
    if cnt2:
        cnt += 1
    ans = max(ans, cnt)

print(ans)
