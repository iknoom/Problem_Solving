n, m, q = map(int, input().split())
penalty = [[0] * m for _ in range(n)]
ac = [0] * n
sum_time = [0] * n
for _ in range(q):
    *tmp, result = input().split()
    t, n_i, m_i = map(int, tmp)
    n_i -= 1
    m_i -= 1
    if penalty[n_i][m_i] < 0:
        continue
    if result == 'AC':
        ac[n_i] += 1
        sum_time[n_i] += t
        sum_time[n_i] += 20 * penalty[n_i][m_i]
        penalty[n_i][m_i] = -1
    else:
        penalty[n_i][m_i] += 1

answer = [(-ac[i], sum_time[i], i) for i in range(n)]
for a, b, c in sorted(answer):
    print(c + 1, -a, b)