X, Y = map(int, input().split())
flag = False
for i in range(X + 1):
    a = i
    b = X - i
    if a * 2 + b * 4 == Y:
        flag = True

if flag:
    print("Yes")
else:
    print("No")