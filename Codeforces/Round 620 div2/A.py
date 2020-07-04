import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    x, y, a, b = map(int, input().split())
    D = y - x
    q = D // (a + b)
    p = D % (a + b)
    if p: print(-1)
    else: print(q)