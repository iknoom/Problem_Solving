INF = float('inf')

N, C = map(int, input().split())
arr = list(map(int, input().split()))
min_idx = {}
count = {}
for i in range(N):
    e = arr[i]
    if e not in min_idx:
        min_idx[e] = i
        count[e] = 1
    else:
        count[e] += 1

answer = []
for e in set(arr):
    answer.append((-count[e], min_idx[e], e))

answer.sort()
for c, _, n in answer:
    for _ in range(-c):
        print(n, end=' ')