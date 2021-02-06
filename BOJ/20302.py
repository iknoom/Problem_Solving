from math import sqrt

def fac(n):
    if n == 0:
        yield 0
        return
    a = n
    for i in range(2, int(sqrt(n)) + 2):
        while a % i == 0:
            a //= i
            yield i
    yield a

N = int(input())
T = input().split()
a = [0] * 100001
b = [0] * 100001

v = abs(int(T[0]))
for k in fac(v):
    a[k] += 1

for i in range(N - 1):
    v = abs(int(T[i * 2 + 2]))
    if T[i * 2 + 1] == '*':
        for k in fac(v):
            a[k] += 1
    else:
        for k in fac(v):
            b[k] += 1

# 0 이면
if a[0] > 0:
    print("mint chocolate")

else:
    ans = "mint chocolate"
    for i in range(2, 100001):
        if a[i] < b[i]:
            ans = "toothpaste"
    print(ans)