N = int(input())
adj = [[] for _ in range(N)]

for i in range(N):
    for j in list(map(int, input().split()))[:-1]:
        adj[i].append(j - 1)

M = int(input())
q = []
time = [-1] * N
cnt = [0] * N
for i in map(int, input().split()):
    time[i - 1] = 0
    q.append(i - 1)

t = 1
while True:
    flag = True
    next_q = []
    for u in q:
        for v in adj[u]:
            if time[v] == -1:
                cnt[v] += 1
                if cnt[v] * 2 >= len(adj[v]):
                    flag = False
                    time[v] = t
                    next_q.append(v)
    t += 1
    if flag:
        break
    q = next_q

print(*time)