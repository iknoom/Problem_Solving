INF = float('inf')

def get_dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)

if __name__ == '__main__':
    # input
    N = int(input())
    W = int(input())
    points = [(-1, -1)] + [tuple(map(int, input().split())) for _ in range(W)]

    # solution
    dp = [[INF] * (W + 1) for _ in range(W + 1)]
    prv = [[(-1, -1)] * (W + 1) for _ in range(W + 1)]
    dp[1][0] = get_dist((1, 1), points[1])
    dp[0][1] = get_dist((N, N), points[1])
    for x in range(W + 1):
        for y in range(W + 1):
            if x == y:
                continue
            if x < y:
                if y - x == 1:
                    for i in range(y - 1):
                        _from = points[i]
                        _to = points[y]
                        if i == 0:
                            _from = (N, N)
                        if dp[x][y] > dp[x][i] + get_dist(_from, _to):
                            dp[x][y] = dp[x][i] + get_dist(_from, _to)
                            prv[x][y] = (x, i)
                else:
                    dp[x][y] = dp[x][y - 1] + get_dist(points[y], points[y - 1])
                    prv[x][y] = (x, y - 1)
            if x > y:
                if x - y == 1:
                    for i in range(x - 1):
                        _from = points[i]
                        _to = points[x]
                        if i == 0:
                            _from = (1, 1)
                        if dp[x][y] > dp[i][y] + get_dist(_from, _to):
                            dp[x][y] = dp[i][y] + get_dist(_from, _to)
                            prv[x][y] = (i, y)
                else:
                    dp[x][y] = dp[x - 1][y] + get_dist(points[x], points[x - 1])
                    prv[x][y] = (x - 1, y)

    # get answer
    answer = INF
    answer_xy = (-1, -1)
    for i in range(W + 1):
        if answer > dp[W][i]:
            answer = dp[W][i]
            answer_xy = (W, i)
        if answer > dp[i][W]:
            answer = dp[i][W]
            answer_xy = (i, W)
    trace = []
    x, y = answer_xy
    while True:
        if x + y == 1:
            if x:
                trace.append(1)
            else:
                trace.append(2)
            break
        else:
            x1, y1 = prv[x][y]
            if x == x1:
                trace.append(2)
            else:
                trace.append(1)
            x, y = x1, y1
    print(answer)
    print(*trace[::-1], sep='\n')