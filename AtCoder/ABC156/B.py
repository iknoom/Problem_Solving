N, K = map(int, input().split())
ans = 0
while N:
    ans += 1
    N //= K
print(ans)