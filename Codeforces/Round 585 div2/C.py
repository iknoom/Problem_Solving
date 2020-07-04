N = int(input())
s = input()
t = input()

sa = []
sb = []

for i in range(N):
    if s[i] == t[i]: continue
    if s[i] == 'a':
        sa.append(i+1)
    if s[i] == 'b':
        sb.append(i+1)

L = len(sa) + len(sb)
if L&1: print(-1)

else:
    if len(sa) & 1:
        print(L//2 + 1)
    else:
        print(L//2)

    while len(sa) >= 2:
        a = sa.pop()
        b = sa.pop()
        print(a,b)
    while len(sb) >= 2:
        a = sb.pop()
        b = sb.pop()
        print(a,b)

    if sa:
        a = sa.pop()
        b = sb.pop()
        print(a, a)
        print(a, b)
