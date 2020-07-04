import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    if n == 1: print(-1)
    else:
        if (2*(n-1)+3)%3 == 0:
            print('2'*(n-2)+'3'*2)
        else:
            print('2' * (n - 1) + '3')
