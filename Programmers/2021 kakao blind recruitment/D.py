INF = 10**18

def solution(n, s, a, b, fares):
    answer = INF
    dp = [[INF] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 0

    for i in range(len(fares)):
        c, d, f = fares[i]
        dp[c - 1][d - 1] = f
        dp[d - 1][c - 1] = f

    # Floyd-Warshall
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

    for mid in range(n):
        ret = dp[s - 1][mid] + dp[mid][a - 1] + dp[mid][b - 1]
        answer = min(answer, ret)
    return answer


if __name__ == "__main__":
    print(solution(6, 4, 6, 2, [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))