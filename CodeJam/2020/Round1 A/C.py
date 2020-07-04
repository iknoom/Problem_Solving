import sys
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

T = int(input())

for case in range(1, T + 1):
    R, C = map(int, input().split())
    B = [list(map(int, input().split())) for _ in range(R)]
    ans = 0
    while True:
        E = 0
        tmp = [[0] * C for _ in range(R)]
        for i in range(R):
            for j in range(C):
                if B[i][j] == 0: continue
                ans += B[i][j]
                SUM = 0
                COUNT = 0
                for p in range(4):
                    x, y = j, i
                    flag = True
                    while True:
                        y, x = y + dy[p], x + dx[p]
                        if 0 <= y < R and 0 <= x < C:
                            if B[y][x]:
                                break
                        else:
                            flag = False
                            break
                    if flag:
                        SUM += B[y][x]
                        COUNT += 1
                if COUNT and B[i][j] * COUNT < SUM:
                    tmp[i][j] = 0
                    E += 1
                else:
                    tmp[i][j] = B[i][j]
        if E == 0:
            break
        for i in range(R):
            for j in range(C):
                B[i][j] = tmp[i][j]
    print("Case #" + str(case) + ":",ans)