import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int,input().split()))

    ans = []

    L = set()

    S = set()
    Max = -1
    for i in range(N):
        Max = max(Max, A[i])
        S.add(A[i])
        if len(S) == i + 1 and i + 1 == Max:
            L.add(i + 1)

    S = set()
    Max = -1
    for i in range(N):
        Max = max(Max, A[-i - 1])
        S.add(A[-i - 1])
        if len(S) == i + 1 and i + 1 == Max:
            if N - i - 1 in L:
                ans.append((N - i - 1, i + 1))
    if ans:
        print(len(ans))
        for a, b in ans:
            print(a, b)
    else:
        print(0)
