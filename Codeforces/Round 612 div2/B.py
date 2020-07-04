import sys
from itertools import combinations as cb
input = sys.stdin.readline

n, k = map(int,input().split())
S = [input().rstrip() for _ in range(n)]

ans = 0
for a, b, c in cb(range(n), 3):
    flag = True
    for i in range(k):
        if S[a][i] == S[b][i] and S[b][i] == S[c][i]:
            continue
        elif S[a][i] != S[b][i] and S[b][i] != S[c][i] and S[a][i] != S[c][i]:
            continue
        else:
            flag = False
            break
    if flag: ans += 1
print(ans)

