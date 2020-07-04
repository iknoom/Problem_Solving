A = [int(input()) for _ in range(10)]
for i in range(9):
    A[i + 1] += A[i]

ans = 10**9
t = -1

for i in range(10):
    if abs(A[i] - 100) < ans:
        ans = abs(A[i] - 100)
        t = A[i]
    elif abs(A[i] - 100) == ans:
        t = max(t, A[i])

print(t)