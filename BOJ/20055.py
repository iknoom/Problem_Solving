

if __name__ == '__main__':
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    belt = [[-1, A[i]] for i in range(N * 2)]
    count = 0
    b_count = 0
    while True:
        count += 1
        # 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. 내리는 위치에 있는 로봇은 내린다.
        belt[N - 1][0] = -1
        belt = belt[-1:] + belt[:-1]
        # belt[N - 1][0] = -1
        # 2. 가장 먼저 벨트에 올라간 로봇부터,
        # 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        # 로봇이 이동하기 위해서는 로봇이 내리는 위치가 아니고, 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        robots = [(belt[i][0], i) for i in range(N) if belt[i][0] >= 0]
        for _, i in sorted(robots):
            if belt[i][0] >= 0 and belt[i + 1][0] < 0 and belt[i + 1][1]:
                belt[i + 1][1] -= 1
                if not belt[i + 1][1]:
                    b_count += 1
                belt[i + 1][0], belt[i][0] = belt[i][0], belt[i + 1][0]
        # 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if belt[0][1]:
            belt[0][1] -= 1
            if not belt[0][1]:
                b_count += 1
            belt[0][0] = count
        # 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
        if b_count >= K:
            break
    print(count)