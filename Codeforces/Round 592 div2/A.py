import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c, d, k = map(int, input().split())
    flag = False
    ans = -1
    for i in range(k):
        if a <= c*i and b <= d*(k-i):
            flag = True
            ans = i
            break
    if flag:
        print(ans, k-ans)
    else:
        print(ans)