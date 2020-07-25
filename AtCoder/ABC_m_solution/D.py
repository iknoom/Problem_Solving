import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

stocks = 0
money = 1000

for i in range(N - 1):
    if A[i] <= A[i + 1]:
        stocks += money // A[i]
        money %= A[i]
    else:
        money += A[i] * stocks
        stocks = 0


money += A[-1] * stocks
print(money)