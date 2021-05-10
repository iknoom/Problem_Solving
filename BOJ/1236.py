# N = 4, M = 4
N, M = map(int, input().split())
Y = set(range(N))
X = set(range(M))

for y in range(N):
    row = input()
    for x in range(M):
        c = row[x]
        if c == 'X':
            Y.discard(y)
            X.discard(x)
print(max(len(X), len(Y)))