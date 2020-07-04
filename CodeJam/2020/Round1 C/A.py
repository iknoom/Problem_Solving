import sys
input = sys.stdin.readline

T = int(input())
dxy = {'E' : (1,0), 'W' : (-1, 0), 'N' : (0, 1), 'S' : (0, -1)}

for case in range(1, T + 1):
    X, Y, M = input().split()
    X = int(X); Y = int(Y)
    ans = 10**9
    for i in range(len(M)):
        dx, dy = dxy[M[i]]
        X += dx; Y += dy
        if abs(X) + abs(Y) <= i + 1:
            ans = min(ans, i + 1)

    if ans == 10**9:
        print("Case #"+str(case) + ": IMPOSSIBLE")
    else:
        print("Case #" + str(case) + ":", ans)