import sys
input = sys.stdin.readline

N, W = map(int, input().split())
A = [int(input()) for _ in range(N)]

coins = 0
money = W

for i in range(N - 1):
    if A[i] <= A[i + 1]:
        coins += money // A[i]
        money %= A[i]
    else:
        money += A[i] * coins
        coins = 0

money += A[-1] * coins
print(money)