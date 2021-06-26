N = int(input())
A = list(map(int, input().split()))
answer = []
K = int(input())
L = N // K
for i in range(K):
    answer += sorted(A[i * L: (i + 1) * L])
print(*answer)