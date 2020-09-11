
if __name__ == "__main__":
    R, C = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(R)]
    dp = [[1] * C for _ in range(R)]
    sweep = []
    for i in range(R):
        for j in range(C):
            sweep.append((A[i][j], i, j))
    sweep.sort(reverse=True)
    for _, y, x in sweep:
        t = A[y][x]
        idx = (y, x)
        for i in range(-1, 2):
            for j in range(-1, 2):
                y1 = y + i
                x1 = x + j
                if 0 <= x1 < C and 0 <= y1 < R and A[y1][x1] < t:
                    t = A[y1][x1]
                    idx = (y1, x1)
        y1, x1 = idx
        tmp = dp[y][x]
        dp[y][x] = 0
        dp[y1][x1] += tmp
    for row in dp:
        print(*row)