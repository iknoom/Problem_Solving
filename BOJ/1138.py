N = int(input())
ans = [0] * N
for i, a in enumerate(map(int, input().split())):
    cnt = 0
    for j in range(N):
        if ans[j] == 0:
            if cnt == a: ans[j] = i + 1; break
            else: cnt += 1
print(*ans)


