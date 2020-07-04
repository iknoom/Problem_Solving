dp = [1, 1, 2] # 0칸 1칸 2칸
for _ in range(40): dp.append(dp[-1] + dp[-2])

N = int(input())
M = int(input())
VIP = [0] + [int(input()) for _ in range(M)] + [N + 1]

ans = 1
for i in range(len(VIP) - 1):
    dx = VIP[i + 1] - VIP[i] - 1
    ans *= dp[dx]
print(ans)