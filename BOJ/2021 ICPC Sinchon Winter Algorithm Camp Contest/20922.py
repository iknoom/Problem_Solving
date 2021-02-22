N, K = map(int, input().split())
A = list(map(int, input().split()))
cnt = [0] * 100001
ans = 0
l = 0
for r in range(N):
    cnt[A[r]] += 1
    while cnt[A[r]] > K:
        cnt[A[l]] -= 1
        l += 1
    ans = max(ans, r - l + 1)
print(ans)