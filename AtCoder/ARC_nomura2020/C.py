N = int(input())
A = list(map(int, input().split()))
flag = True
if A[0] != 0:
    flag = False

ans = 0
cur = 1

nodes = [0] * (N + 1)
nodes[0] = 1
for i in range(1, N + 1):
    cur *= 2
    nodes[i] = cur
    cur -= A[i]
    if cur < 0:
        flag = False

L = 0
for i in range(N, -1, -1):
    L += A[i]
    L = min(L, nodes[i])
    ans += L

if N == 0:
    if A[0] == 1:
        print(1)
    else:
        print(-1)
elif flag:
    print(ans)
else:
    print(-1)