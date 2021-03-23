from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
count = [0] * N
adj = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    count[b] += 1

answer = [-1] * N
p = 1
while True:
    q = []
    for i in range(N):
        if answer[i] < 0 and count[i] == 0:
            q.append(i)
    if not q:
        break
    for a in q:
        answer[a] = p
        for b in adj[a]:
            count[b] -= 1
    p += 1

print(*answer)
