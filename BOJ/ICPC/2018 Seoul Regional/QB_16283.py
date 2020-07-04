A, B, n, w = map(int, input().split())
a = b = cnt = 0
for i in range(1, n):
    if A * i + B * (n - i) == w:
        a = i
        b = n-i
        cnt += 1
if cnt == 1:
    print(a, b)
else:
    print(-1)