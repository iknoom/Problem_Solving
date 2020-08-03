K = int(input())

ans = -1
dr = 7
r = 0

for i in range(K):
    r = (r + dr) % K
    if r == 0:
        ans = i + 1
        break
    dr = (r * 10) % K

print(ans)
