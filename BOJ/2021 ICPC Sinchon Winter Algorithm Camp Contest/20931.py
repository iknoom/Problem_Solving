from sys import stdin, maxsize
input = stdin.readline
INF = maxsize
PSIZE = 18

# log(Q)
def ad_hoc(x, L)
    k = (x + last_answer) % M
    p_i = [-1]  PSIZE
    pL_i = [-1]  PSIZE
    p_i[0] = k
    pL_i[0] = L
    for j in range(1, PSIZE)
        p_i[j] = p[p_i[j - 1]][j - 1]
        if p_i[j]  0 break
        pL_i[j] = pL_i[j - 1] + pL[p_i[j - 1]][j - 1]
    p.append(p_i)
    pL.append(pL_i)

# log(Q)
def query(x, L)
    for j in range(PSIZE - 1, -1, -1)
        if p[x][j]  0
            continue
        if pL[x][j] = L
            L -= pL[x][j]
            x = p[x][j]
    return x

if __name__ == __main__
    # sparse matrix
    p = []
    pL = []

    # ad_hoc 0
    p_0 = [-1]  PSIZE
    pL_0 = [-1]  PSIZE
    p.append(p_0)
    pL.append(pL_0)

    # solution
    last_answer = 0
    M = 1
    Q = int(input())
    for _ in range(Q)
        ad_or_qry, x_str, L_str = input().split()
        x, L = int(x_str), int(L_str)
        if ad_or_qry == ad-hoc
            ad_hoc(x, L)
            M += 1
        elif ad_or_qry == query
            last_answer = query(x, L)
            print(last_answer)