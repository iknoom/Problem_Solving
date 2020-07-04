from collections import deque
N, K, M = map(int, input().split())

# 0 ~ N - 1     : 역
# N ~ N + M - 1 : 하이퍼튜브
adj = [[] for _ in range(N)] + [list(map(int, input().split())) for _ in range(M)]

# (역 -> 하이퍼튜브) 연결
for i in range(M):
    for k in adj[N + i]:
        adj[k - 1].append(N + i + 1)

# 0-1 bfs
q = deque([1])
vst = [0] * (N + M)
vst[0] = 1

while q:
    u = q.popleft()
    for v in adj[u - 1]:
        if vst[v - 1]: continue
        if v > N:
            vst[v - 1] = vst[u - 1]         # 하이퍼튜브 -> 역
            q.appendleft(v)                 # vst에 0을 더하고 push_left
        else:
            vst[v - 1] = vst[u - 1] + 1     # 나머지 경우
            q.append(v)                     # vst에 1을 더하고 push_right

# 만약 vst == 0 이면 -1 출력
if vst[N - 1]:
    print(vst[N - 1])
else:
    print(-1)