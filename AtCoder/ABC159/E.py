H, W, K = map(int,input().split())
B = [list(map(int, input())) for _ in range(H)]

CHOCO = [[] for _ in range(1<<(H-1))]
cnt = [10**9] * (1<<(H-1))

for i in range(1<<(H-1)):
    S = 0
    ret = []
    flag = True
    for j in range(H - 1):
        S += B[j][0]
        if i & (1<<j):
            if S > K:
                flag = False
            ret.append(S)
            S = 0
    S += B[-1][0]
    if S > K:
        flag = False
    ret.append(S)
    if flag:
        CHOCO[i] = ret[:]
        cnt[i] = len(ret) - 1


for w in range(1,W):
    for i in range(1 << (H - 1)):
        if not CHOCO[i]: continue

        S = 0
        ret = []
        flag1 = True
        for j in range(H - 1):
            S += B[j][w]
            if i & (1 << j):
                if S > K:
                    flag1 = False
                ret.append(S)
                S = 0
        S += B[-1][w]
        ret.append(S)

        flag2 = True

        for j in range(len(ret)):
            if ret[j] + CHOCO[i][j] > K:
                flag2 = False

        if flag1:
            if flag2:
                for j in range(len(ret)):
                    CHOCO[i][j] += ret[j]
            else:
                CHOCO[i] = ret[:]
                cnt[i] += 1
        else:
            CHOCO[i] = []

print(min(cnt))