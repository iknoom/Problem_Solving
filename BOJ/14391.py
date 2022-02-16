from sys import setrecursionlimit
setrecursionlimit(10 ** 6)

def dfs(bitset, sum_point):
    for y in range(N):
        for x in range(M):
            idx = y * M + x
            if bitset & (1 << idx):
                continue
            ret = 0
            # row
            row_point = 0
            row_bitset = bitset
            for y1 in range(y, N):
                idx1 = y1 * M + x
                if row_bitset & (1 << idx1):
                    break
                row_point = row_point * 10 + board[y1][x]
                row_bitset |= (1 << idx1)
                ret = max(ret, dfs(row_bitset, sum_point + row_point))
            # col
            col_point = board[y][x]
            col_bitset = bitset | (1 << idx)
            for x1 in range(x + 1, M):
                idx1 = y * M + x1
                if col_bitset & (1 << idx1):
                    break
                col_point = col_point * 10 + board[y][x1]
                col_bitset |= (1 << idx1)
                ret = max(ret, dfs(col_bitset, sum_point + col_point))
            return ret
    return sum_point

if __name__ == '__main__':
    N, M = map(int, input().split())
    board = [list(map(int, input())) for _ in range(N)]
    answer = dfs(0, 0)
    print(answer)