import math
from itertools import combinations as cb
X = int(input())

if X == 1:
    print(1, 1)
    exit()

ans = {}

k = X
while True:
    if k == 1: break
    q = k

    for i in range(2, int(math.sqrt(k))+2):
        if k % i == 0:
            if i in ans:
                ans[i] *= i
            else: ans[i] = i
            k //= i
            break
    if k == q:
        if k in ans:
            ans[k] *= k
        else:
            ans[k] = k
        break

Q = list(ans.values())
R = []
for i in range(1, len(Q)+1):
    for W in cb(Q, i):
        tmp = 1
        for w in W:
            tmp *= w
        R.append((max(tmp, X//tmp), min(tmp, X//tmp)))

R.sort()
print(R[0][1], R[0][0])