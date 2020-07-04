import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
R = {'L' : 0, 'R' : 1, 'U' : 2, 'D' : 3}

T = int(input())

for _ in range(T):
    x = y = 0
    N = int(input())
    Path = input().rstrip()

    vst = {(0, 0) : 0}
    ans = []
    for i in range(N):
        #print(x, y)
        r = R[Path[i]]
        x += dx[r]
        y += dy[r]
        if (x, y) in vst:
            w = i - vst[(x, y)]
            ans.append((w, vst[(x, y)] + 1, i + 1))

        vst[(x, y)] = i + 1
    ans.sort()

    if ans:
        print(ans[0][1], ans[0][2])
    else:
        print(-1)


