from itertools import combinations as cb

c = list(map(int,input().split()))

cc = sum(c)

ans = "NO"

for g in cb(c, 2):
    if sum(g) == cc//2:
        ans = "YES"

for k in c:
    if k == cc//2:
        ans = "YES"

if cc & 1: ans = "NO"

print(ans)