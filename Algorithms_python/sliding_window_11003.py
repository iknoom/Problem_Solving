INF = 10**9
N, L = map(int, input().split())
A = [INF] * L + list(map(int, input().split())) + [INF] * L
ans = []
for i in range(L, N + L, L):
    stack = [A[i]]
    right = left = A[i]
    for j in range(L - 1):
        left = min(left, A[i - j - 1])
        stack.append(left)
    for j in range(L):
        right = min(right, A[i + j])
        ans.append(min(stack.pop(), right))
print(*ans[:N])