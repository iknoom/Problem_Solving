N, S = map(int, input().split())
A = list(map(int, input().split()))

answer = 0
for i in range(1, 1 << N):
    cur = 0
    for j in range(N):
        if i & (1 << j):
            cur += A[j]
    if cur == S:
        answer += 1
print(answer)
