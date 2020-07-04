import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    a = input().rstrip()
    b = input().rstrip()
    c = input().rstrip()
    N = len(a)
    flag = True
    for i in range(N):
        if a[i] == c[i] or b[i] == c[i]:
            continue
        else:
            flag = False
    if flag:
        print("YES")
    else:
        print("NO")