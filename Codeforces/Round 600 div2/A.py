import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = [0] * (N+1)
    ans = "YES"
    for i in range(N):
        c[i] = b[i] - a[i]

    prv = 0
    cnt = 0
    for i in range(N+1):
        if c[i] < 0:
            ans = "NO"
        if c[i] != prv:
            prv = c[i]
            cnt += 1
    if cnt > 2:
        ans = "NO"
    print(ans)