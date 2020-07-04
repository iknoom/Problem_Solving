N = int(input())
T = input()
L = 0
R = 0
for k in T:
    if k == 'L':
        L += 1
    else:
        R += 1
print(L+R+1)