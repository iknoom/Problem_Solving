N = int(input())
a = list(map(int, input().split()))
dp = [-10 ** 18] * N

def eval_a(s, e):
    ret = 0
    c = 0
    for i in range(s, e + 1):
        c += 1
        ret += c * a[i]
    return ret

for i in range(N):
    dp[i] = eval_a(0, i)
    if i > 0: dp[i] = max(dp[i], eval_a(1, i))
    if i > 1: dp[i] = max(dp[i], eval_a(2, i))
    for j in range(0, i - 1):
        dp[i] = max(dp[i], dp[j] + eval_a(j + 2, i))
    for j in range(0, i - 2):
        dp[i] = max(dp[i], dp[j] + eval_a(j + 3, i))

print(max(0, max(dp[-3:])))