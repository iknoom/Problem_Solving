W = list(map(int, input().split()))
vst = set()
ans = set()
q = [(0, 0, W[2])]

for cur in q:
    if cur[0] == 0: ans.add(cur[2])
    for i in range(3):
        for k in range(1,3):
            next = list(cur[:])
            next[(i + k)%3] += next[i]
            if next[(i + k) % 3] > W[(i + k) % 3]:
                next[i] = next[(i + k) % 3] - W[(i + k) % 3]
                next[(i + k) % 3] = W[(i + k) % 3]

            else:
                next[i] = 0
            next = tuple(next)
            if next not in vst:
                vst.add(next)
                q.append(next)
print(*sorted(ans))
