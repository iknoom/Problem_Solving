A, B = map(int, input().split())
Ax = A * 25
if Ax & 1:
    Ax += 1
Ay = (A + 1) * 25
if Ay & 1:
    Ay += 1
Ax //= 2
Ay //= 2
Bx = B * 10
By = (B + 1) * 10

if Ay <= Bx or By <= Ax:
    print(-1)
else:
    ans = max(Bx, Ax)
    print(ans)