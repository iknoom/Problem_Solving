X, Y = map(int, input().split())
if X < Y:
    X, Y = Y, X
print(X + Y + Y // 10)