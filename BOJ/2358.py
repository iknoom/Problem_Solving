from sys import stdin
from collections import defaultdict
input = stdin.readline

N = int(input())
xset = defaultdict(int)
yset = defaultdict(int)
for _ in range(N):
    x, y = map(int, input().split())
    xset[x] += 1
    yset[y] += 1

print(sum((v > 1) for v in list(yset.values()) + list(xset.values())))
