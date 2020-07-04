T = int(input())

for case in range(1, T + 1):
    N = int(input())
    LR = []
    ans = [''] * N
    for i in range(N):
        a, b = map(int,input().split())
        LR.append((a, 1, i))
        LR.append((b, 0, i))
    C = J = -1

    LR.sort()

    is_impossible = False

    for x, t, i in LR:
        if t:
            if C < 0:
                C = i
                ans[i] = 'C'
            elif J < 0:
                J = i
                ans[i] = 'J'
            else: is_impossible = True; break
        else:
            if C == i: C = -1
            elif J == i: J = -1
    if is_impossible: ans = "IMPOSSIBLE"
    else: ans = ''.join(ans)

    print("Case #"+str(case) + ":", ans)