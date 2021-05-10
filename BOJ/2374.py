n = int(input())
A = [int(input()) for _ in range(n)]
answer = 0
queue = [(0, n)]
for l, r in queue:
    m = max(range(l, r), key=A.__getitem__)
    if m != l:
        answer += A[m] - max(A[l:m])
        queue.append((l, m))
    if m != r - 1:
        answer += A[m] - max(A[m + 1:r])
        queue.append((m + 1, r))
print(answer)