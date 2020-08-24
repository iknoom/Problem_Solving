from collections import defaultdict

w, n = map(int, input().split())
A = list(map(int, input().split()))
D = defaultdict(list)

for i in range(n - 1):
    for j in range(i + 1, n):
        if i == j: continue
        D[A[i] + A[j]].append((i, j))

ans = "NO"
for L in D.keys():
    R = w - L
    if R not in D: continue
    if len(D[L]) > 2 or len(D[R]) > 2:
        ans = "YES"
    else:
        for l in D[L]:
            for r in D[R]:
                if l[0] != r[0] and l[0] != r[1] and l[1] != r[0] and l[1] != r[1]:
                    ans = "YES"
print(ans)