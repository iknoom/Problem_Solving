MOD = 10 ** 9 + 7

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    dp = [1] * N
    answer = 1
    for k in range(2, N + 1):
        next_dp = [0] * N
        k_dp = [0] * k
        S = 0
        for i in range(N):
            S += A[i]
            S %= k
            next_dp[i] += k_dp[S]
            next_dp[i] %= MOD
            k_dp[S] += dp[i]
            k_dp[S] %= MOD
        answer += next_dp[-1]
        answer %= MOD
        dp = next_dp
    print(answer)