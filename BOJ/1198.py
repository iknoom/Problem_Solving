N = int(input())
ans = -1

p = [tuple(map(int, input().split())) for _ in range(N)]

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            S = abs(((p[j][0] - p[i][0]) * (p[k][1] - p[i][1]) - (p[j][1] - p[i][1]) * (p[k][0] - p[i][0])))
            ans = max(ans, S / 2)
print(ans)