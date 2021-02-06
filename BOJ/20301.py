from collections import deque

N, K, M = map(int, input().split())
dq = deque(range(1, N + 1))
t = -1
for i in range(1, N + 1):
    dq.rotate(t * K)
    if t == -1:
        print(dq.pop())
    else:
        print(dq.popleft())
    if i % M == 0:
        t *= -1