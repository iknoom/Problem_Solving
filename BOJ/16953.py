A, B = map(int, input().split())
q = [(A, 0)]
vst = set()
ans = -1
for a, cnt in q:
    if a == B:
        ans = cnt + 1
        break
    if a > B: continue
    for a0 in  [a * 2, a * 10 + 1]:
        if a0 not in vst:
            vst.add(a0)
            q.append((a0, cnt + 1))

print(ans)