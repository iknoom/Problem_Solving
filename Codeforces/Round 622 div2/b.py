import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, x, y = map(int, input().split())
    k1 = x + y - 1
    k2 = x + y

    if k1 > n:
        ans1 = n
    else:
        ans1 = k1

    if k2 >= n:
        ans2 = max(0, k2 - 1 - (k2 - n) * 2)
    else:
        ans2 = n - 1

    print(n - ans2, ans1)