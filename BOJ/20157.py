from math import gcd
from collections import Counter
from sys import stdin
input = stdin.readline

C = Counter()
N = int(input())
for _ in range(N):
    x, y = map(int, input().split())
    g = gcd(x, y)
    C[(x//g, y//g)] += 1
print(max(C.values()))