from collections import Counter
N, K = map(int, input().split())
C = list(map(int, input().split()))
# candy
cnt = Counter()

colors = 0
for i in range(K):
    cnt[C[i]] += 1
    if cnt[C[i]] == 1:
        colors += 1

answer = colors
for i in range(K, N):
    cnt[C[i]] += 1
    if cnt[C[i]] == 1:
        colors += 1

    j = i - K

    cnt[C[j]] -= 1
    if cnt[C[j]] == 0:
        colors -= 1

    answer = max(answer, colors)

print(answer)