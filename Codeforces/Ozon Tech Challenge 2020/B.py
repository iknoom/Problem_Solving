S = input()
N = len(S)

ans = []
vst = [False] * N
is_ans = 0
for _ in range(2):

    ret = []
    L = 0
    R = N - 1
    while L < R:
        while L < N and ( vst[L] or S[L] == ')'):
            L += 1
        while R >= 0 and ( vst[R] or S[R] == '('):
            R -= 1
        if L >= N or R < 0 or L > R: break
        ret.append(L+1)
        ret.append(R+1)
        vst[L] = True
        vst[R] = True
        L += 1
        R -= 1
    if ret: is_ans += 1
    ans.append(ret)

if is_ans:
    print(is_ans)
    for k in ans:
        if k:
            print(len(k))
            print(*sorted(k))
else:
    print(0)
