import sys

input = sys.stdin.readline

q = int(input())

for _ in range(q):
    S = 'R' + input().rstrip() + 'R'
    ans = -1
    prv = 0
    for i in range(1, len(S)):
        if S[i] == 'R':
            diff = i - prv
            ans = max(ans, diff)
            prv = i
    print(ans)
