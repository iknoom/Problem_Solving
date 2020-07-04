X = int(input())

q = [X]
vst = {X : -1}

for x in q:
    if x == 1: break
    t = [x - 1]
    if x % 2 == 0: t.append(x // 2)
    if x % 3 == 0: t.append(x // 3)
    for y in t:
        if y > 0 and y not in vst:
            vst[y] = x
            q.append(y)
Q = 1
ans = []
while Q > 0:
    ans.append(Q)
    Q = vst[Q]

print(len(ans) - 1)
print(*ans[::-1])