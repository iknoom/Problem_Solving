n = int(input())
ab = [tuple(map(int, input().split())) for _ in range(n)]
M = int(input())
ans = 0
for T in range(1, 101001):
    flag = True
    C = 0
    for i in range(n):
        a, b = ab[i]
        if a + b > T:
            flag = False
            break
        if (T - b) % a:
            flag = False
            break
        x = (T - b) // a
        C += x
    if flag and C == M:
        ans = T
        break
print(ans)