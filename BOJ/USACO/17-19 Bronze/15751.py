x, y, a, b = map(int,input().split())
if y < x: x, y = y, x
if b < a: a, b = b, a
print(min(y-x, abs(x-a)+abs(y-b)))
