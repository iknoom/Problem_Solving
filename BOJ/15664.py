N, M = map(int,input().split())
A = sorted(map(int,input().split()))
def sol(i, S):
    if len(S) == M:
        print(*S)
        return
    for j in range(i + 1, len(A)):
        if j > i + 1 and A[j] == A[j - 1]: continue
        sol(j, S + [A[j]])
sol(-1,[])