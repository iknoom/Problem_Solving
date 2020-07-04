import sys
input = sys.stdin.readline

T = int(input())

for case in range(1, T + 1):
    X, Y = map(int, input().split())
    tmp = 0
    while (1 << tmp) <= abs(X) or (1 << tmp) <= abs(Y): tmp += 1
    q = [(X, Y, '', tmp - 1)]

    I = 65
    for i in range(I + 1):
        diff = (1 << i)
        q.append((X - diff, Y, 'E', i))
        q.append((X + diff, Y, 'W', i))
        q.append((X, Y - diff, 'N', i))
        q.append((X, Y + diff, 'S', i))

    ans = []

    for x, y, c, J in q:
        a, b = x, y
        ret = []
        flag = True

        P = 0
        while (1 << P) <= abs(X) or (1 << P) <= abs(Y): P += 1
        P -= 1
        if P < J: ret.append(c)
        while P >= 0:
            if P == J: ret.append(c)
            elif abs(a) & (1 << P):
                if a > 0: ret.append('E'); a -= (1 << P)
                else: ret.append('W'); a += (1 << P)
            elif abs(b) & (1 << P):
                if b > 0: ret.append('N'); b -= (1 << P)
                else: ret.append('S'); b += (1 << P)
            else:
                flag = False
                break
            P -= 1
        if a == 0 and b == 0 and flag:
            ans.append(''.join(ret[::-1]))

    if not ans: print("Case #"+str(case) + ": IMPOSSIBLE")
    else:
        V = ans[0]
        for W in ans[1:]:
            if len(W) < len(V):
                V = W
        print("Case #" + str(case) + ": "+V)