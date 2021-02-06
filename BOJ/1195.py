A = list(map(int, input()))
B = list(map(int, input()))
N = len(A)
M = len(B)
NM = N + M + M - 2
ALL = [0] * NM
for i in range(N):
    ALL[M - 1 + i] = A[i]

ans = N + M - 1

for i in range(NM - M):
    tmp = ALL[:]
    flag = True
    for j in range(M):
        if B[j] == 2 and tmp[i + j] == 2:
            flag = False
        tmp[i + j] = 3

    if flag:
        index = [i for i in range(NM) if tmp[i]]
        ans = min(ans, max(index) - min(index))

print(ans + 1)