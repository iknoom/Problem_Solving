import sys
input = sys.stdin.readline


N, X, T = map(int, input().split())

ans = N // X
if N % X != 0:
    ans += 1


print(ans * T)