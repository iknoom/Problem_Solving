N, M = map(int, input().split())
s = []
c = []
for _ in range(M):
    a, b = map(int, input().split())
    s.append(a)
    c.append(b)
ans = [-1] * N
flag = True
for i in range(M):
    if N > 1 and s[i] == 1 and c[i] == 0: flag = False
    if ans[s[i] - 1] < 0:
        ans[s[i] - 1] = c[i]
    elif ans[s[i] - 1] != c[i]:
        flag = False


for i in range(N):
    if ans[i] < 0:
        ans[i] = 0

if ans[-N] == 0 and N > 1:
    ans[-N] = 1

if flag:
    print(''.join(map(str, ans)))
else:
    print(-1)