from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N, M = map(int, input().split())
    dp = [0] * (N + 1)
    D = [0] + [int(input()) for _ in range(N)]
    for i in range(N):
        D[i + 1] += D[i]
    # solution
    for i in range(1, N + 1):
        dp[i] = dp[i - 1]
        for k in range(2, i + 1, 2):
            if k // 2 > M + 1:
                break
            dp[i] = max(dp[i], dp[i - k] + (D[i - k // 2] - D[i - k]))
    print(dp[-1])