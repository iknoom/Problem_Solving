import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, r = map(int, input().split())
    ans = 0

    if n > r:
        ans = r * (r + 1) // 2
    elif n == r:
        ans = r * (r - 1) // 2 + 1
    else:
        ans = n * (n - 1) // 2 + 1
    print(ans)