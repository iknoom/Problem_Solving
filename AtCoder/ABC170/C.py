nums = set(range(-200, 200))

X, N = map(int, input().split())
p = set(map(int, input().split()))
dist = 10**9
ans = 10**9

for k in sorted(nums - p):
    if abs(X - k) < dist:
        ans = k
        dist = abs(X - k)
print(ans)