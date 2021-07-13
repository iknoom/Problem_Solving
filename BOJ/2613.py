INF = float('inf')

N, M = map(int, input().split())
A = list(map(int, input().split()))
dp = [[(INF, -1)] * (M + 1) for _ in range(N)]

for i in range(N):
    sum_value = 0
    j = i
    while j >= 0:
        sum_value += A[j]
        if j == 0:
            dp[i][1] = (sum_value, -1)
        else:
            for k in range(2, M + 1):
                cur_max = max(dp[j - 1][k - 1][0], sum_value)
                if dp[i][k][0] > cur_max:
                    dp[i][k] = (cur_max, j - 1)
        j -= 1

print(dp[-1][-1][0])
answer = []
cur_i = N - 1
cur_j = M
while cur_i >= 0:
    nxt = dp[cur_i][cur_j][1]
    answer.append(cur_i - nxt)
    cur_i = nxt
    cur_j -= 1
print(*answer[::-1])