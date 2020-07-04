N = int(input())
L = 0
R = 0
lq = 0
rq = 0
TK = input()

for i in range(N//2):
    if TK[i] == '?':
        lq += 1
    else:
        L += int(TK[i])

for i in range(N//2, N):
    if TK[i] == '?':
        rq += 1
    else:
        R += int(TK[i])

if lq == rq:
    if L == R:
        print('Bicarp')
    else:
        print('Monocarp')

t = abs(lq - rq)

if lq > rq:
    R -= L
    if R < 0:
        print('Monocarp')
    else:
        if (t//2) * 9 == R:
            print('Bicarp')
        else:
            print('Monocarp')

if lq < rq:
    L -= R
    if L < 0:
        print('Monocarp')
    else:
        if (t // 2) * 9 == L:
            print('Bicarp')
        else:
            print('Monocarp')