N = int(input())
q = list(range(10))
for k in q:
    r = k % 10
    y = k * 10
    for x in range(r): q.append(x + y)
if N < len(q):
    print(q[N])
else:
    print(-1)