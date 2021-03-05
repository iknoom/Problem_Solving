MAX = 30005

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    dp = [False] * MAX
    dp[0] = True
    for a in A:
        next_dp = dp[:]
        for i in range(MAX):
            if dp[i]:
                next_dp[(i + a) % MAX] = True
                next_dp[i - a] = True
        dp = next_dp

    M = int(input())
    B = list(map(int, input().split()))
    S = sum(A)
    for b in B:
        if b <= S and dp[b]:
            print('Y', end=' ')
        else:
            print('N', end=' ')