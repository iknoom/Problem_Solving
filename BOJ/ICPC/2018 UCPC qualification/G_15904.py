f = "UCPC"
i = 0
for a in input():
    if i == 4: break
    if a == f[i]: i += 1

if i == 4:
    print("I love UCPC")
else:
    print("I hate UCPC")