import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, g, b = map(int, input().split())
    if n <= g:
        print(n)
        continue

    Bd = n//2
    Gd = n - Bd

    Y = Bd // b
    y = Bd % b

    n -= Y * (g + b)
    if n <= y:
        print(n)
        continue

    print(Y, n)
