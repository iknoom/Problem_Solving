N = int(input())
P = [list(map(int,input().split())) for _ in range(N)]
W = B = 0

def sol(x, y, n):
    global W, B
    S = sum(sum(P[i][x:x+n]) for i in range(y,y+n))
    if S == 0: W += 1
    elif S == n * n: B += 1
    else:
        n //= 2
        sol(x, y, n)
        sol(x + n, y, n)
        sol(x, y + n, n)
        sol(x + n, y + n, n)
sol(0, 0, N)
print(W)
print(B)