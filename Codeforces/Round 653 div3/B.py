import sys
input = sys.stdin.readline


T = int(input())

for _ in range(T):
    n = int(input())
    ans = 0
    while n != 1:

        if n % 6 == 0:
            ans += 1
            n //= 6
        elif n % 3 == 0:
            ans += 2
            n //= 3
        else:
            break
    if n == 1:
        print(ans)
    else:
        print(-1)

