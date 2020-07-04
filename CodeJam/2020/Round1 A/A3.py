import sys
input = sys.stdin.readline

T = int(input())

for case in range(1, T + 1):
    N = int(input())

    P = [input().rstrip() for _ in range(N)]
    ans1 = P[0]
    flag = True
    for i in range(1,N):
        tmp = []
        a = b = 0
        A = len(P[i])
        B = len(ans1)
        while a < A and b < B:

            if P[i][a] == '*':
                while ans1[b] != '*':
                    tmp.append(ans1[b])
                    b += 1
                tmp.append("*")
                ans1 = ''.join(tmp)
                break
            elif ans1[b] == '*':
                while P[i][a] != '*':
                    tmp.append(P[i][a])
                    a += 1
                tmp.append("*")
                ans1 = ''.join(tmp)
                break
            elif P[i][a] == ans1[b]:
                tmp.append(ans1[b])
                a += 1
                b += 1
            elif P[i][a] != ans1[b]:
                flag = False
                break

    P2 = [P[i][::-1] for i in range(N)]
    ans2 = P2[0]
    for i in range(1, N):
        tmp = []
        a = b = 0
        A = len(P2[i])
        B = len(ans2)
        while a < A and b < B:

            if P2[i][a] == '*':
                while ans2[b] != '*':
                    tmp.append(ans2[b])
                    b += 1
                tmp.append("*")
                ans2 = ''.join(tmp)
                break
            elif ans2[b] == '*':
                while P2[i][a] != '*':
                    tmp.append(P2[i][a])
                    a += 1
                tmp.append("*")
                ans2 = ''.join(tmp)
                break
            if P2[i][a] == ans2[b]:
                tmp.append(ans2[b])
                a += 1
                b += 1
            elif P2[i][a] != ans2[b]:
                flag = False
                break

    mid = []
    for i in range(N):
        X = P[i]
        l = 0
        r = len(X) - 1
        while X[l] != '*': l += 1
        while X[r] != '*': r -= 1
        for i in range(l, r):
            if X[i] != '*':
                mid.append(X[i])


    ans1 = ans1[:-1]
    XX = ''.join(mid)
    ans2 = ans2[:-1]

    if flag:
        print("Case #"+str(case) + ": "+ans1+XX+ans2[::-1])
    else:
        print("Case #" + str(case) + ": " + "*")