N = int(input())
T = [0] * N
adj = [[] for _ in range(N)]
cnt = [0] * N
for i in range(N):
    tmp = list(map(int, input().split()))
    T[i] = tmp[0]
    cnt[i] = tmp[1]
    for t in tmp[2:]:
        adj[t- 1].append(i)

stack = []
for i in range(N):
    if not cnt[i]: stack.append(i)

dp = [0] * N
while stack:
    u = stack.pop()
    dp[u] += T[u]
    for v in adj[u]:
        cnt[v] -= 1
        dp[v] = max(dp[v], dp[u])
        if cnt[v] == 0:
            stack.append(v)

print(max(dp))
