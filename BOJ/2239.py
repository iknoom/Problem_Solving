g = [list(map(int,input())) for _ in range(9)]
z = [(x, y) for y in range(9) for x in range(9) if g[y][x]==0]

def dfs(i):
    if i == len(z):
        for h in g: print(''.join(map(str,h)))
        exit()
    x, y = z[i]
    cnt = set(range(1,10))
    for r in range(9):
        cnt.discard(g[y][r])
        cnt.discard(g[r][x])
    for p in range(y//3*3, y//3*3+3):
        for q in range(x//3*3, x//3*3+3):
            cnt.discard(g[p][q])
    for n in cnt:
        g[y][x] = n
        dfs(i + 1)
        g[y][x] = 0
dfs(0)