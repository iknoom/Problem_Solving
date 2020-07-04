import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a,b,c,r = map(int,input().split())
    if a > b: a,b = b,a
    q,p = c-r, c+r

    if b < q or p < a: print(b - a)
    elif a <= q and p <= b: print(b - a - r - r)
    elif q < a and b < p: print(0)
    elif b < p: print(q - a)
    elif q < a: print(b - p)