import sys
input = sys.stdin.readline


T = int(input())

for _ in range(T):
    x, y, n = map(int, input().split())
    ans = (n//x) * x + y
    if ans > n:
        ans -= x
    print(ans)