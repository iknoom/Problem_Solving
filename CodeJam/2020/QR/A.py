import sys
input = sys.stdin.readline

T = int(input())

for case in range(1, T + 1):
    N = int(input())
    M = [list(map(int,input().split())) for _ in range(N)]

    k = sum(M[i][i] for i in range(N))
    r = sum(len(set(M[i])) != N for i in range(N))
    M = [*zip(*M)]
    c = sum(len(set(M[i])) != N for i in range(N))

    print("Case #"+str(case) + ":", k, r, c)