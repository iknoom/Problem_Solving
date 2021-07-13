H, Y = map(int, input().split())
dp = [H]
for _ in range(Y):
    ret = -1
    if len(dp) >= 1:
        ret = max(ret, int(dp[-1] * 1.05))
    if len(dp) >= 3:
        ret = max(ret, int(dp[-3] * 1.2))
    if len(dp) >= 5:
        ret = max(ret, int(dp[-5] * 1.35))
    dp.append(ret)
print(dp[-1])