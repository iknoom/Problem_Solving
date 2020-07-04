N = int(input())
A = list(map(int, input().split()))
M = -1
ans = []
x = y = A[-1]
for i in range(1,N-1):
    x = min(x, A[-i-1])
    y += A[-i-1]
    ret = (y - x) / i
    if M < ret:
        M = max(M, ret)
        ans = [N - 1 - i]
    elif M == ret:
        ans.append(N - 1 - i)
print(*sorted(ans), sep='\n')