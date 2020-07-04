a, b, c = map(int, input().split())

L = 4 * a * b
R = c - b - a

if L < R * R and R >= 0:
    print("Yes")
else:
    print("No")