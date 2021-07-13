from bisect import bisect_left, bisect
from sys import stdin
input = stdin.readline
INF = float('inf')

N, Q = map(int, input().split())
A = [-INF] + sorted(map(int, input().split())) + [INF]
for _ in range(Q):
    a, b = map(int, input().split())
    print(bisect(A, b) - bisect_left(A, a))