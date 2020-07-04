def solve():
    i = j = 0
    min_dst = 10 ** 16
    cnt = 0

    while True:
        if i == n or j == m: break

        if abs(Q[j] - P[i]) < min_dst:
            min_dst = abs(Q[j] - P[i])
            cnt = 1
        elif abs(Q[j] - P[i]) == min_dst:
            cnt += 1

        # print("#", P[i], Q[j], "#", cnt, "#", abs(Q[j] - P[i]), min_dst)

        if Q[j] - P[i] < min_dst:
            j += 1
        else:
            i += 1
    return min_dst, cnt


if __name__ == "__main__":
    n, m = map(int, input().split())
    c1, c2 = map(int, input().split())

    P = list(map(int, input().split()))
    Q = list(map(int, input().split()))

    P.sort()
    Q.sort()

    min_dst, cnt = solve()

    print(min_dst + abs(c1-c2), cnt)