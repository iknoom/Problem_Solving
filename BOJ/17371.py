import math

N = int(input())
P = [tuple(map(int, input().split())) for _ in range(N)]
INF = float('inf')

min_dist = INF
ans = -1

for i in range(N):
    S1 = 0
    S2 = INF
    for j in range(N):
        d = math.sqrt((P[i][0] - P[j][0])**2 + (P[i][1] - P[j][1])**2)
        S1 = max(S1, d)
        S2 = min(S2, d)
    if S1 + S2 < min_dist:
        min_dist = S1 + S2
        ans = i

print(*P[ans])