import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    S = input().rstrip()
    N = len(S)
    L = 0
    R = N - 1
    while L < R and S[L] == S[R]:
        L += 1
        R -= 1
    if L == R:
        print(S)
        continue

    SUB = S[L: R+1]
    M = len(SUB)

    fail1 = [0] * M
    j = 0
    for i in range(1, M):
        while j > 0 and SUB[i] != SUB[j]: j = fail1[j - 1]
        if SUB[i] == SUB[j]:
            j += 1
            fail1[i] = j

    SUB2 = SUB[::-1]
    fail2 = [0] * M
    j = 0
    for i in range(1, M):
        while j > 0 and SUB2[i] != SUB2[j]: j = fail2[j - 1]
        if SUB2[i] == SUB2[j]:
            j += 1
            fail2[i] = j


    j = 0
    for i in range(M):
        while j > 0 and SUB[i] != SUB2[j]: j = fail2[j - 1]
        if SUB[i] == SUB2[j]: j += 1
    ans1 = S[:L] + S[R-j+1:R+1] + S[R+1:]


    j = 0
    for i in range(M):
        while j > 0 and SUB2[i] != SUB[j]: j = fail1[j - 1]
        if SUB2[i] == SUB[j]: j += 1
    ans2 = S[:L] + S[L:L+j] + S[R + 1:]


    if len(ans1) < len(ans2):
        print(ans2)
    else:
        print(ans1)




