#  비트마스킹 dp 
# dp[10][1  16][10] = (last, bits, remainder)

def solve(bits, n_bits, last)
    # 마지막 카드를 선택하지 않은 경우
    if last == -1
        for i in range(N)
            last = cards[i]
            next_bits = bits - (1  i)
            solve(next_bits, n_bits - 1, last)
            for j in range(last)
                dp[last][bits][j] += dp[last][next_bits][j]
        return
    # dp가 이미 채워져 있는 경우
    elif visited[last][bits]
        return
    # dp가 채워져 있지 않은 경우
    for i in range(N)
        if not (bits & (1  i))
            continue
        next_bits = bits - (1  i)
        solve(next_bits, n_bits - 1, last)
        diff = cards[i]  (10  (n_bits - 1))
        diff %= last
        for j in range(last)
            dp[last][bits][(j + diff) % last] += dp[last][next_bits][j]
    visited[last][bits] = True

if __name__ == __main__
    # input
    N = int(input())
    cards = list(map(int, input().split()))

    # dp, visited
    dp = [[[0]  10 for _ in range((1  N))] for _ in range(10)]
    visited = [[False]  (1  N) for _ in range(10)]
    for i in range(10)
        visited[i][0] = True
        dp[i][0][0] = 1

    # solution
    all_bits = (1  N) - 1
    solve(all_bits, N, -1)
    success_cases = 0
    all_cases = 0
    for i in range(10)
        success_cases += dp[i][all_bits][0]
        all_cases += sum(dp[i][all_bits])
    print(success_cases  all_cases)