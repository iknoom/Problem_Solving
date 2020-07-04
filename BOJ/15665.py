N, M = map(int,input().split())
A = sorted(set(map(int,input().split())))
def sol(S):
    if len(S) == M:
        print(*S)
        return
    for i in range(len(A)):
        sol(S + [A[i]])
sol([])