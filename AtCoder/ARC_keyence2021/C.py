from sys import stdin
MOD = 998244353
input = stdin.readline

if __name__ == "__main__":
    H, W, K = map(int, input().split())
    B = [[None] * W for _ in range(H)]
    dp = [[0] * W for _ in range(H)]
    for _ in range(K):
        hs, ws, c = input().split()
        h, w = int(hs), int(ws)
        h -= 1
        w -= 1
        B[h][w] = c
    dp[0][0] = 1

    row_zeros = [1] * W
    for y in range(H):
        col_zero = 1
        for x in range(W):
            if x > 0:
                if B[y][x - 1] in ['X', 'R']:
                    dp[y][x] += dp[y][x - 1] * row_zeros[x]
                if B[y][x - 1] == None:
                    dp[y][x] += dp[y][x - 1] * row_zeros[x] * 2
            if y > 0:
                if B[y - 1][x] in ['X', 'D']:
                    dp[y][x] += dp[y - 1][x] * col_zero
                if B[y - 1][x] == None:
                    dp[y][x] += dp[y - 1][x] * col_zero * 2
            dp[y][x] %= MOD
            if B[y][x] == None:
                row_zeros[x] *= 3
                row_zeros[x] %= MOD
                col_zero *= 3
                col_zero %= MOD

    if B[-1][-1] == None:
        print(dp[-1][-1] * 3 % MOD)
    else:
        print(dp[-1][-1] % MOD)
