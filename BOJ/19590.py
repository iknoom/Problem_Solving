from sys import stdin
input = stdin.readline
N = int(input())
x = [int(input()) for _ in range(N)]
S = sum(x)
mx = max(x)
if mx > S - mx:
    print(mx + mx - S)
else:
    print(S % 2)