import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    if N & 1:
        ans = '7'
        N -= 3
        ans = ans + (N // 2) * '1'
    else:
        ans = (N // 2) * '1'

    print(ans)