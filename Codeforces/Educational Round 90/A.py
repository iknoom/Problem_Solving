import sys
input = sys.stdin.readline


t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())
    L = 1
    R = b
    if a >= c:
        L = -1
    if a * b <= c:
        R = -1
    print(L, R)