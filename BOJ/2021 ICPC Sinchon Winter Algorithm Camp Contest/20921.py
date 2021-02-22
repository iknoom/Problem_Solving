N, K = map(int, input().split())
answer = []
l = 1
r = N
for i in range(N):
    cur = N - i - 1
    if K >= cur:
        K -= cur
        answer.append(r)
        r -= 1
    else:
        answer.append(l)
        l += 1
print(*answer)