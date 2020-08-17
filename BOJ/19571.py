B = [[0] * 100 for _ in range(100)]

p = 1
q = 0

for i in range(100):
    for j in range(100):
        if i == 99 - j:
            B[i][j] = 10000 - q
            q += 1
        else:
            B[i][j] = p
            p += 1

for b in B:
    print(*b)
