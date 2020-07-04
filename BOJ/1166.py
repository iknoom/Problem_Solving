N, L, W, H = map(int, input().split())
l = float(10**(-9))
r = float(10**9 + 1)
T = 100
for _ in range(T):
    mid = (l + r) / 2
    if (L // mid) * (W // mid) * (H // mid) >= N:
        l = mid
    else:
        r = mid
print(l)