import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    pipe = [list(map(int,input().rstrip())) for _ in range(2)]
    dp = [[False]*(N+1) for _ in range(2)]
    dp[0][0] = True

    for i in range(N):
        if pipe[0][i] <= 2 and dp[0][i]:
            dp[0][i+1] = True

        if pipe[1][i] <= 2 and dp[1][i]:
            dp[1][i+1] = True

        if pipe[0][i] > 2 and pipe[1][i] > 2:
            if dp[0][i]: dp[1][i+1] = True
            if dp[1][i]: dp[0][i+1] = True

    if dp[1][-1]: print("YES")
    else: print("NO")

