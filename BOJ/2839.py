N = int(input())
q = N // 5
r = N % 5

if r == 0:
    print(q)
elif r == 1:
    print(q + 1 if q >= 1 else -1)
elif r == 2:
    print(q + 2 if q >= 2 else -1)
elif r == 3:
    print(q + 1)
elif r == 4:
    print(q + 2 if q >= 1 else -1)