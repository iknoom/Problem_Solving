from sys import stdin
input = stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]
dp = []
for i in range(N):
    ret = 0
    for j in range(i):
        if A[j] < A[i]:
            ret = max(ret, dp[j])
    dp.append(ret + A[i])
print(max(dp))