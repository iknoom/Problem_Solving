N, C = map(int, input().split())
A = list(map(int, input().split()))
X = set(A)
ans = False
if C in X: ans = True
for i in range(N - 1):
    for j in range(i + 1, N):
        y = C - A[i] - A[j]
        if y == 0: ans = True
        if y in X and y != A[i] and y != A[j]: ans = True
if ans: print(1)
else: print(0)