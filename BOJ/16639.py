N = int(input())
E = input()
M = N // 2 + 1
max_dp = [[-10 ** 9] * M for _ in range(M)]
min_dp = [[10 ** 9] * M for _ in range(M)]

for i in range(M):
    max_dp[i][i] = min_dp[i][i] = int(E[i * 2])

for k in range(1,M):
    for i in range(M - k):
        j = i + k
        for x in range(i, j):
            #최댓값
            max_dp[i][j] = max(max_dp[i][j], eval(str(max_dp[i][x]) + E[x * 2 + 1] + str(max_dp[x + 1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(min_dp[i][x]) + E[x * 2 + 1] + str(max_dp[x + 1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(max_dp[i][x]) + E[x * 2 + 1] + str(min_dp[x + 1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(min_dp[i][x]) + E[x * 2 + 1] + str(min_dp[x + 1][j])))

            #최솟값
            min_dp[i][j] = min(min_dp[i][j], eval(str(max_dp[i][x]) + E[x * 2 + 1] + str(max_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(min_dp[i][x]) + E[x * 2 + 1] + str(max_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(max_dp[i][x]) + E[x * 2 + 1] + str(min_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(min_dp[i][x]) + E[x * 2 + 1] + str(min_dp[x + 1][j])))

print(max_dp[0][-1])