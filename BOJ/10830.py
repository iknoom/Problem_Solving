MOD = 1000
N, B = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
ret = [[int(j == i) for i in range(N)] for j in range(N)]

def mul_MOD(A, B):
    global N, MOD
    ret = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            ret[i][j] = sum(A[i][k] * B[k][j] for k in range(N)) % 1000
    for i in range(N):
        for j in range(N):
            A[i][j] = ret[i][j]

while B:
    if B & 1:
        mul_MOD(ret, A)
        B -= 1
    mul_MOD(A, A)
    B //= 2

for k in ret: print(*k)

