import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    x = 1
    while x < 10**16 + 1: x *= k

    while x:
        for i in range(n):
            if a[i] >= x:
                a[i] -= x
                break
        x //= k
    if sum(a) == 0:
        print("YES")
    else:
        print("NO")