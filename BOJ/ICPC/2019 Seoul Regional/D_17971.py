N = int(input())
L = [list(map(int, input().split()))[:-1] for _ in range(N-1)]
after = list(range(N))
ladders = []
for i in range(N-1):
    for j in range(len(L[i])):
        ladders.append((L[i][j], i, j))
ladders.sort()

for _, i, _ in ladders:
    after[i], after[i + 1] = after[i + 1], after[i]

M = len(ladders)
vst = [0] * M
before = list(range(N))

for i in range(N):
    predict = cur = after[i]
    end = i

    for j in range(M):
        _, x, _ = ladders[j]
        if x == predict and vst[j] > 0: predict += 1
        elif x + 1 == predict and vst[j] > 0: predict -= 1

    for j in range(M):
        _, x, _ = ladders[j]
        if vst[j] < 0:  # deleted
            continue
        if x == cur: # to right
            if vst[j] > 0: # visited
                cur += 1
            elif end <= predict: # delete
                vst[j] = -1
            else:
                vst[j] = 1
                cur += 1
                predict -= 1

        elif x + 1 == cur: # to left
            if vst[j] > 0: # visited
                cur -= 1
            elif end >= predict: # delete
                vst[j] = -1
            else:
                vst[j] = 1
                cur -= 1
                predict += 1

ans = []
for i in range(M):
    if vst[i] > 0:
        _, x, y = ladders[i]
        ans.append((x + 1, y + 1))

print(len(ans))
for x, y in ans:
    print(x, y)