import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int,input().split())
    y = k//2
    x = k-y
    a = n //(x+y)
    ans1 = x*a + y*a
    tmp = n - ans1

    print(ans1 + min(tmp, y))