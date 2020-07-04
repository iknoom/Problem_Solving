import sys
input = sys.stdin.readline

S = input().rstrip()

st = ''
ed = ''

flag = 1

q = int(input())

for _ in range(q):
    Q = input().split()
    if len(Q) == 1:
        flag ^= 1

    else:
        if int(Q[1]) == 1:
            if flag: st += Q[2]
            else: ed += Q[2]
        else:
            if flag: ed += Q[2]
            else: st += Q[2]

if flag: print(st[::-1] + S + ed)
else: print(ed[::-1] + S[::-1] + st)