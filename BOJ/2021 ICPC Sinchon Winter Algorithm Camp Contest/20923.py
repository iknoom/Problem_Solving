from collections import deque
N, M = map(int, input().split())
dq = [deque([]) for _ in range(2)]
grd = [deque([]) for _ in range(2)]

for _ in range(N):
    do, su = map(int, input().split())
    dq[0].append(do)
    dq[1].append(su)

answer = ""

for i in range(M):
    t = i & 1
    grd[t].append(dq[t].pop())
    if not dq[t]:
        answer = "su" if t == 0 else "do"
        break
    # su
    if grd[0] and grd[1] and grd[0][-1] + grd[1][-1] == 5:
        while grd[0]:
            dq[1].appendleft(grd[0].popleft())
        while grd[1]:
            dq[1].appendleft(grd[1].popleft())
    # do
    if (grd[0] and grd[0][-1] == 5) or (grd[1] and grd[1][-1] == 5):
        while grd[1]:
            dq[0].appendleft(grd[1].popleft())
        while grd[0]:
            dq[0].appendleft(grd[0].popleft())

if not answer:
    if len(dq[0]) == len(dq[1]):
        answer = "dosu"
    elif len(dq[0]) > len(dq[1]):
        answer = "do"
    else:
        answer = "su"

print(answer)