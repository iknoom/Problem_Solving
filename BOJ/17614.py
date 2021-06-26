N = int(input())
ans = 0
for i in range(1, N + 1):
    for c in str(i):
        if c in '369':
            ans += 1
print(ans)