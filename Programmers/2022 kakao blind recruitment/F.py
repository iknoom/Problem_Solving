def solution(board, skill):
    N = len(board)
    M = len(board[0])
    diff_board = [[0] * (M + 1) for _ in range(N + 1)]
    for type, r1, c1, r2, c2, degree in skill:
        if type == 1:
            degree = -degree
        diff_board[r1][c1] += degree
        diff_board[r1][c2 + 1] -= degree
        diff_board[r2 + 1][c1] -= degree
        diff_board[r2 + 1][c2 + 1] += degree
    for r in range(N + 1):
        row_diff = 0
        for c in range(M + 1):
            row_diff += diff_board[r][c]
            diff_board[r][c] = row_diff
    for c in range(M + 1):
        col_diff = 0
        for r in range(N + 1):
            col_diff += diff_board[r][c]
            diff_board[r][c] = col_diff
    answer = 0
    for r in range(N):
        for c in range(M):
            if board[r][c] + diff_board[r][c] >= 1:
                answer += 1
    return answer

if __name__ == '__main__':
    print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]],	[[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))