N = int(input())
S = list(map(int, input().split()))
all_num = set(range(1, 2000001))
for i in range(1 << N):
    sum_S = 0
    for j in range(N):
        if i & (1 << j):
            sum_S += S[j]
    all_num.discard(sum_S)
print(min(all_num))