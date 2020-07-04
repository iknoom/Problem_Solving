N = int(input())
S = input()

R = 0
G = 0
B = 0
ans = 0
for i in range(N):
    if S[i] == 'R':
        R += 1
        ans += G * B
    elif S[i] == 'G':
        G += 1
        ans += R * B
    elif S[i] == 'B':
        B += 1
        ans += R * G


L = 1
while L * 2 + 1 <= N:
    for i in range(N - L * 2):
        Q = [S[i], S[i + L], S[i + L + L]]
        if len(set(Q)) == 3:
            ans -= 1
    L += 1

print(ans)