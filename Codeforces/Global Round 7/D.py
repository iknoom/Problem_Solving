import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    S = input().rstrip()
    N = len(S)
    ans = -1
    ans_s = ''

    dp = [[-1] * N for _ in range(N)]
    for i in range(N): dp[i][i] = 1
    for i in range(N - 1):
        if S[i] == S[i + 1]:
            dp[i][i + 1] = 1
        else:
            dp[i][i + 1] = 0

    for k in range(2, N + 1):
        for i in range(N - k):
            j = i + k
            if dp[i + 1][j - 1] > 0 and S[i] == S[j]:
                dp[i][j] = 1
            else:
                dp[i][j] = 0

    if dp[0][-1]:
        print(S)
        continue

    p = 0
    while S[p] == S[-p-1]:
        p += 1


    L = p
    R = N - p - 1

    for i in range(L, R):
        if dp[L][i]:
            sub = S[:L] + S[L:i+1] + S[R+1:]
            if ans < len(sub):
                ans = len(sub)
                ans_s = sub

    for i in range(R, L, -1):
        if dp[i][R]:
            sub = S[:L] + S[i:R+1] + S[R+1:]
            if ans < len(sub):
                ans = len(sub)
                ans_s = sub


    print(ans_s)




