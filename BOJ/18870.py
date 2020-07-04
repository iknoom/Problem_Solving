N = int(input())
X = list(map(int, input().split()))
D = {}
for i, k in enumerate(sorted(set(X))): D[k] = i
print(*(D[k] for k in X))