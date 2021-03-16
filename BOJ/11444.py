MOD = 10**9 + 7

def mul_square(A, B):
    n = len(A)
    ret = [[0] * n for _ in range(n)]
    for r in range(n):
        for c in range(n):
            for i in range(n):
                ret[r][c] += A[r][i] * B[i][c]
                ret[r][c] %= MOD
    return ret

def pow_square(A, k):
    n = len(A)
    ret = [[0] * n for _ in range(n)]
    for i in range(n):
        ret[i][i] = 1
    while k:
        if k % 2:
            ret = mul_square(ret, A)
        A = mul_square(A, A)
        k //= 2
    return ret

if __name__ == '__main__':
    n = int(input())
    M = [[0, 1],
         [1, 1]]
    answer = pow_square(M, n)
    print(answer[0][1])