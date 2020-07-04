import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int,input().split()))
    ans = 0
    for i in range(N):
        if not A[i]:
            A[i] += 1
            ans += 1

    if sum(A) != 0:
        print(ans)
    else:
        flag = False
        for a in A:
            if a != -1:
                flag = True

        if flag: print(ans + 1)
        else: print(ans + 2)

