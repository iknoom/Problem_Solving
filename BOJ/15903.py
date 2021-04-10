n, m = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(m):
    a.sort()
    S = a[0] + a[1]
    a[0] = a[1] = S
print(sum(a))