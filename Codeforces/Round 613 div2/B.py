import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    T = list(map(int,input().split()))
    a = sum(T)
    ans = True
    i = s = 0
    while i < N - 1:
        s += T[i]
        if s >= a:
            ans = False
        if s < 0:
            s = 0
        i += 1

    i = 1
    s = 0
    while i < N:
        s += T[i]
        if s >= a:
            ans = False
        if s < 0:
            s = 0
        i += 1

    if ans:
        print("YES")
    else:
        print("NO")