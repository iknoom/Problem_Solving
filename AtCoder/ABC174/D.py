N = int(input())
C = input()

cnt_R = 0

for i in range(N):
    if C[i] == 'R':
        cnt_R += 1


ans = min(cnt_R, N - cnt_R)

cnt_swap = 0
for i in range(cnt_R):
    if C[i] != 'R':
        cnt_swap += 1


print(min(ans, cnt_swap))