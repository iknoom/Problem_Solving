N = int(input())
A = list(map(int, input().split()))
answer = sum(A[1:-1]) + max(A[1:-1])

# left
L = sum(A[1:])
S = A[-1]
for i in range(N - 2, 0, -1):
    answer = max(answer, L + S - A[i])
    S += A[i]

# right
R = sum(A[:-1])
S = A[0]
for i in range(1, N - 1):
    answer = max(answer, R + S - A[i])
    S += A[i]

print(answer)