m ,n, k = map(int, input().split())
T = ['R', 'L', 'U', 'D']

if n < m :
    n, m = m, n
    T = ['D', 'U', 'L', 'R']

max_k = 4 * n * m - 2 * (n + m)


def print_ans():
    print(len(ans))
    for t, k in ans:
        print(t, k)
    exit()

if max_k < k:
    print("NO")

else:
    print("YES")
    ans = []

    if k <= n - 1:
        ans.append((k, T[0]))
        print_ans()
    ans.append((n - 1, T[0]))
    k -= n - 1

    if k <= n - 1:
        ans.append((k, T[1]))
        print_ans()
    ans.append((n - 1, T[1]))
    k -= n - 1

    if k <= (4 * (n - 1) + 1) * (m - 1):
        X = k // (4 * (n - 1) + 1)
        Y = k % (4 * (n - 1) + 1)
        for _ in range(X):
            ans.append((1, T[3]))
            ans.append((n - 1, T[0]))
            ans.append((n - 1, T[2]+T[3]+T[1]))

        if Y == 0:
            print_ans()

        if Y == 1:
            ans.append((1, T[3]))
            print_ans()

        ans.append((1, T[3]))
        Y -= 1

        if Y <= n - 1:
            ans.append((Y, T[0]))
            print_ans()
        ans.append((n - 1, T[0]))
        Y -= n - 1

        p = Y // 3
        q = Y % 3
        if p:
            ans.append((p, T[2]+T[3]+T[1]))
        if q:
            r = T[2]+T[3]+T[1]
            ans.append((1, r[:q]))
        print_ans()

    for _ in range(m - 1):
        ans.append((1, T[3]))
        ans.append((n - 1, T[0]))
        ans.append((n - 1, T[2] + T[3] + T[1]))
    k -= (4 * (n - 1) + 1) * (m - 1)
    ans.append((k, T[2]))
    print_ans()
