import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    K = list(map(int, input().split()))
    S = sum(K)
    x = y = 0
    for k in K:
        if k&1:
            x += 1
        else:
            y += 1

    if S & 1:
        print("YES")
    else:
        if x and y:
            print("YES")
        else:
            print("NO")