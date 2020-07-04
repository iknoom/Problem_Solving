N = int(input())
M = int(input())
S = input()

p = 0
ans = 0

while p < M:
    if S[p] == 'I':
        cnt = 0
        while p < M - 2 and S[p + 1] == 'O' and S[p + 2] == 'I':
            cnt += 1
            p += 2
        ans += max(0, cnt - N + 1)
    p += 1

print(ans)