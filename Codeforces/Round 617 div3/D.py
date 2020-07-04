n, a, b, k = map(int, input().split())
H = list(map(int,input().split()))
ans = 0

TQ = []

for h in H:
    h %= a + b
    if not h:
        h += a + b
    x = (h - 1) // a
    if x: TQ.append(x)
    else: ans += 1

TQ.sort()

for tq in TQ:
    if k >= tq:
        k -= tq
        ans += 1
    else:
        break

print(ans)