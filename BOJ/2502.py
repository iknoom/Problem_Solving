def sol_equ(a, b, c):
    # ax + by = c
    # x <= y
    # (c - ax) % b == 0
    for x in range(1, 100000):
        if (c - a * x) % b == 0:
            y = (c - a * x) // b
            if x <= y:
                return x, y


if __name__ == '__main__':
    D, K = map(int, input().split())
    dp_first = [1, 0]
    dp_second = [0, 1]
    for _ in range(D - 2):
        dp_first.append(dp_first[-2] + dp_first[-1])
        dp_second.append(dp_second[-2] + dp_second[-1])
    a, b = dp_first[-1], dp_second[-1]
    x, y = sol_equ(a, b, K)
    print(x)
    print(y)