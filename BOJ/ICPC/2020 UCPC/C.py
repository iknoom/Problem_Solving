
def make_fact(n, mod):
    fact = [1, 1]
    for i in range(2, n + 1):
        fact.append((fact[-1] * i) % mod)
    return fact



N = int(input())

ans = 1
MOD = 10**9 + 7
fact = make_fact(1000, MOD)

MATRIX = [''.join(input().split()) for _ in range(N)]
vst = [False] * N


for i in range(N):
    if vst[i]: continue

    row = MATRIX[i]
    cnt = set()

    for i in range(N):
        if MATRIX[i] == row: cnt.add(i)

    for c in cnt:
        vst[c] = True


    if len(cnt) > 1:
        M = sum(i == '1' for i in row)


        ans *= fact[M - 1]
        ans %= MOD

        for i in range(N):
            if i in cnt: continue
            flag = True
            row_i = MATRIX[i]
            cnt_one = 0
            for j in range(N):
                if row_i[j] == '0' and row[j] == '1':
                    flag = False
                if row_i[j] == '1':
                    cnt_one += 1
            if flag and cnt_one == M + 1:
                ans *= M
                ans %= MOD

print(ans)