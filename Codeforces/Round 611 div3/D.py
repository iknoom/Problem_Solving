from collections import deque

n, m = map(int,input().split())
queue = deque([])
vst = set()
for k in map(int,input().split()):
    vst.add(k)
    queue.append((k,0))

ans = 0
ans_L = []
cnt = 0

while queue:
    x, step = queue.popleft()
    for dx in [1, -1]:
        X = x + dx
        if X not in vst:
            cnt += 1
            vst.add(X)
            ans += step + 1
            ans_L.append(X)
            queue.append((X, step + 1))
        if cnt == m:
            break
    if cnt == m:
        break

print(ans)
print(*ans_L)




