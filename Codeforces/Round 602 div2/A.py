import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    L = [0] * N
    R = [0] * N
    for i in range(N):
        l,r = map(int,input().split())
        L[i] = l
        R[i] = r
    ans = max(L) - min(R)
    if ans > 0: print(ans)
    else: print(0)