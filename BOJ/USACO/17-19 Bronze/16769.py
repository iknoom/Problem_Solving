c = [0, 0, 0]
m = [0, 0, 0]
for i in range(3):
    x, y = map(int, input().split())
    c[i] = x
    m[i] = y
cnt = 0
while cnt < 100:
    t = cnt % 3
    r = (cnt + 1) % 3
    if m[t] + m[r] <= c[r]:
        m[t], m[r] = 0, m[t] + m[r]
    else:
        m[t], m[r] = m[t] + m[r] - c[r], c[r]
    cnt += 1
print(*m, sep='\n')