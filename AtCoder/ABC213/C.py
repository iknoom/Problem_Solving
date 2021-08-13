from sys import stdin
input = stdin.readline

H, W, N = map(int, input().split())
xaxis = set()
yaxis = set()
# N: i
# HW-N: nothing

cood = [tuple(map(int, input().split())) for _ in range(N)]
for x, y in cood:
    xaxis.add(x)
    yaxis.add(y)

xidx = sorted(xaxis)
yidx = sorted(yaxis)
xdic = {}
ydic = {}

for i in range(len(xidx)):
    xdic[xidx[i]] = i + 1

for i in range(len(yidx)):
    ydic[yidx[i]] = i + 1

for x, y in cood:
    print(xdic[x], ydic[y])

