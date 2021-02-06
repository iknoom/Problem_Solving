from sys import stdin
from collections import deque
input = stdin.readline
N, M = map(int, input().split())
recipes = [list(map(int, input().split())) for _ in range(M)]
L = int(input())
cur_potions = set(map(int, input().split()))
adj = [list() for _ in range(N + 1)]
count = [0] * M
for i in range(M):
    recipe = recipes[i]
    k, r = recipe[0], recipe[-1]
    for j in range(1, k + 1):
        if recipe[j] not in cur_potions:
            adj[recipe[j]].append(i)
            count[i] += 1

queue = deque([])
for i in range(M):
    if count[i] == 0:
        queue.append(i)

while len(queue) > 0:
    i = queue.popleft()
    recipe = recipes[i]
    r = recipe[-1]
    if r in cur_potions:
        continue
    cur_potions.add(r)
    for j in adj[r]:
        count[j] -= 1
        if count[j] == 0:
            queue.append(j)

print(len(cur_potions))
print(*sorted(cur_potions))