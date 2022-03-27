import sys

input = sys.stdin.readline
MOD = 998244353

fac = [1]
for i in range(2, 1001):
    fac.append(fac[-1] * i % MOD)

def solution():
    n = int(input())
    if n % 2 == 1:
        print(0)
    else:
        m = n // 2
        print(fac[m - 1] * fac[m - 1] % MOD)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()