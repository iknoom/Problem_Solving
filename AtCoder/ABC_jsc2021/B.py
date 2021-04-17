from sys import stdin
from collections import Counter
input = stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = Counter(A + B)

answer = []
for key in C.keys():
    if C[key] == 1:
        answer.append(key)

print(*sorted(answer))