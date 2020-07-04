import sys
input = sys.stdin.readline

for _ in range(int(input())):
    t = list(map(int,input().split()))
    t.sort()
    a,b,c = t
    d = c - b
    if d < a:
        c -= (d + (a-d)//2)
        b -= ((a-d) - (a-d)//2)
    else:
        c -= a

    print(a + min(b,c))

