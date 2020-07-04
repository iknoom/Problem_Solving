N = int(input())

d = 1
pl = 0
mn = 0
apl = 0
amn = 0
for k in map(int,input().split()):
    if k < 0: d = d * (-1)

    if d < 0:
        apl += mn
        amn += pl
    else:
        apl += pl
        amn += mn

    if d < 0:
        mn += 1
        amn += 1
    else:
        pl += 1
        apl += 1

print(amn, apl)

