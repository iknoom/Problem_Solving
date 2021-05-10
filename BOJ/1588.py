
def get_count(N):
    count = [[(1, 0, 0)],
             [(0, 1, 0)],
             [(0, 0, 1)]]
    for _ in range(N):
        for i in range(3):
            a, b, c = count[i][-1]
            count[i].append((a + b * 2,
                          b + a + c * 2,
                          c + a))
    return count

def solve(x, time, left, right):
    all = 3 ** time
    if right - left + 1 == all:
        return pre_count[x][time]
    t = all // 3
    a, b, c = 0, 0, 0
    x_set = [(0, 2, 1), (1, 0, 0), (1, 2, 1)]
    for next_x in x_set[x]:
        if left <= t and 0 <= right:
            da, db, dc = solve(next_x, time - 1, max(0, left), min(t - 1, right))
            a += da
            b += db
            c += dc
        left -= t
        right -= t
    return a, b, c

if __name__ == '__main__':
    x = int(input()) - 1
    L = int(input())
    R = int(input())
    N = int(input())
    pre_count = get_count(N)
    print(*solve(x, N, L, R))