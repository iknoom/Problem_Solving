from collections import Counter
from sys import stdin
input = stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]
# 1
print(round(sum(arr) / N))
# 2
print(sorted(arr)[N // 2])
# 3
C = Counter(arr)
maxValue = -1
maxIdx = []
for x in C.keys():
    if maxValue < C[x]:
        maxIdx = [x]
        maxValue = C[x]
    elif maxValue == C[x]:
        maxIdx.append(x)
if len(maxIdx) == 1:
    print(maxIdx[0])
else:
    print(sorted(maxIdx)[1])
# 4
print(max(arr) - min(arr))