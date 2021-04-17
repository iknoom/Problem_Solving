from sys import stdin
from collections import Counter
input = stdin.readline

A, B = map(int, input().split())
C = Counter()
for n in range(A, B + 1):
    p = []
    for i in range(1, n + 5):
        if i * i > n:
            break
        if i * i == n:
            C[i] += 1
        elif n % i == 0:
            C[i] += 1
            C[n//i] += 1
answer = -1

for k in C.keys():
    if C[k] > 1:
        answer = max(answer, k)
print(answer)