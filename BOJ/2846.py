N = int(input())
L = list(map(int,input().split()))
ans = 0
s = L[0]
prv = L[0]
for k in L[1:]:
    if prv < k:
        prv = k
    else:
        s = prv = k
    ans = max(ans, prv - s)
print(ans)