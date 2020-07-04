N = int(input())

ans1 = ''
ans2 = ''
for i in range(N):
    if i&1:
        ans1 += 'W'
        ans2 += 'B'
    else:
        ans1 += 'B'
        ans2 += 'W'

for i in range(N):
    if i&1:
        print(ans1)
    else:
        print(ans2)