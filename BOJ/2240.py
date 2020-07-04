N, W = map(int, input().split())
p = [[0] * (W + 1) for _ in range(2)]
p[1][0] = -10**9
for _ in range(N):
    k = int(input()) - 1
    for i in range(W + 1): p[k][i] += 1
    for j in range(2):
        for i in range(W):
            p[j][i + 1] = max(p[j][i + 1], p[j ^ 1][i])
print(max(p[0] + p[1]))