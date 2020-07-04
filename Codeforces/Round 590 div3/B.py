from collections import deque
N, K = map(int, input().split())
X = list(map(int,input().split()))
is_queue = set()
queue = deque([])
for x in X:
    if x in is_queue:
        continue
    elif len(queue) == K:
        y = queue.pop()
        is_queue.remove(y)
    queue.appendleft(x)
    is_queue.add(x)

print(len(queue))
print(*queue)