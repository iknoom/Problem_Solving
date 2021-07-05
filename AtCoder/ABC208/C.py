N, K = map(int, input().split())
A = list(map(int, input().split()))
# the ID of the i-th citizen is ai. Here, all ai are pairwise different.
# N <= K: all += 1
# else: kth += 1

answer = [K // N] * N
idx = [(A[i], i) for i in range(N)]
idx.sort()
for _, i in idx[:K % N]:
    answer[i] += 1

print(*answer, sep='\n')