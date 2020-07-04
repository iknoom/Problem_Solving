from itertools import combinations as cb

C = set()
cows = []
ans = "yes"

for _ in range(int(input())):
    cow = set(input().split()[1:])
    C |= cow
    cows.append(cow)

for u, v in cb(C, 2):
    a = b = ab = False
    for cow in cows:
        if u in cow and v in cow: ab = True
        elif u in cow: a = True
        elif v in cow: b = True
    if a and b and ab: ans = "no"

print(ans)