from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
arr = []
for _ in range(N):
    u, v = map(int, input().split())
    arr.append((v, -u))
arr.sort()

answer = []
S = 0
cnt = 0
before = -1
for a, b in arr:
    b = -b
    S += b
    if before != a:
        cnt = 1
        before = a
    else:
        cnt += 1
    if S >= M:
        answer.append(cnt * a)

if answer:
    print(min(answer))
else:
    print(-1)