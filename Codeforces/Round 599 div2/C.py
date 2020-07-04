import sys
import math
input = sys.stdin.readline

N = int(input())
k = N
ans = set()

while True:
    if k == 1 : break
    q = k
    for i in range(2,int(math.sqrt(k))+2):
        if k % i == 0:
            ans.add(i)
            k //= i
            break
    if k == q:
        ans.add(k)
        break

if N == 1: print(1)
elif len(ans) == 1: print(*ans)
else: print(1)