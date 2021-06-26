if __name__ == '__main__':
    N, M = map(int, input().split())
    profit = [[0] * M]
    for _ in range(N):
        arr = list(map(int, input().split()))
        profit.append(arr[1:])

    # solution
    value = [[-1] * (N + 1) for _ in range(M + 1)]
    money = [[-1] * (N + 1) for _ in range(M + 1)]
    value[0][0] = 0
    for now in range(1, M + 1):
        for i in range(N + 1):
            now_money = i
            now_profit = profit[i][now - 1]
            for j in range(N):
                if j + now_money > N:
                    break
                if value[now - 1][j] < 0:
                    continue
                next_value = value[now - 1][j] + now_profit
                if value[now][j + now_money] < next_value:
                    value[now][j + now_money] = next_value
                    money[now][j + now_money] = i
    trace = []
    cur = N
    for i in range(M, 0, -1):
        diff = money[i][cur]
        trace.append(diff)
        cur -= diff
    print(value[M][N])
    print(*trace[::-1])