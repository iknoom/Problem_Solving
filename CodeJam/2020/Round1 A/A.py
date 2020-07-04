import sys
input = sys.stdin.readline

T = int(input())

for case in range(1, T + 1):
    N = int(input())
    P = [input().rstrip()[::-1] for _ in range(N)]
    ans = P[0]
    flag = True
    for i in range(1,N):
        tmp = []
        a = b = 0
        A = len(P[i])
        B = len(ans)
        while a < A and b < B:
            if P[i][a] == ans[b]:
                tmp.append(ans[b])
                a += 1
                b += 1
            elif P[i][a] == '*':
                while b < B:
                    tmp.append(ans[b])
                    b += 1
                ans = ''.join(tmp)
                break
            elif ans[b] == '*':
                while a < A:
                    tmp.append(P[i][a])
                    a += 1
                ans = ''.join(tmp)
            elif P[i][a] != ans[b]:
                flag = False
                break

    if ans != "*":
        ans = ans[:-1]
    if flag:
        print("Case #"+str(case) + ": "+ans[::-1])
    else:
        print("Case #" + str(case) + ": " + "*")