from sys import stdin
input = stdin.readline

while True:
    a, _b, _c = input().rstrip().split()
    b = int(_b)
    c = int(_c)
    if b + c == 0:
        break
    if b > 17 or c >= 80:
        print(a, "Senior")
    else:
        print(a, "Junior")