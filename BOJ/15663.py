N, M = map(int, input().split())
A = [-1] + sorted(map(int, input().split()))
vst = [False] * (N + 1)

def sol(arr):
    if len(arr) == M:
        print(*arr)
        return
    for i in range(1, N + 1):
        if not vst[i]:
            if A[i] == A[i - 1] and not vst[i - 1]: continue
            vst[i] = True
            sol(arr + [A[i]])
            vst[i] = False
sol([])