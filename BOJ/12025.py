pw = list(map(int, input()))
k = int(input()) - 1
N = len(pw)
cnt = 0
tmp = 0

for i in range(N):
    if pw[-i - 1] in [1, 2, 6, 7]:
        if k & (1 << cnt):
            if pw[-i - 1] in [1, 6]:
                pw[-i - 1] = 6
            else:
                pw[-i - 1] = 7
            tmp += (1 << cnt)
        else:
            if pw[-i-1] in [1, 6]:
                pw[-i - 1] = 1
            else:
                pw[-i - 1] = 2
        cnt += 1

if k == tmp:
    print(''.join(map(str, pw)))
else:
    print(-1)