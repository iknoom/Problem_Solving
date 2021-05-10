N = int(input())
P = list(map(int, input().split()))
T = int(input())

P.sort()
crash = 0
ALL = 0
for x in range(1 << N):
    ALL += 1
    for i in range(N - 1):
        if not x & (1 << i):
            continue
        for j in range(i + 1, N):
            if x & (1 << j):
                continue
            if P[j] - P[i] <= T * 2:
                crash += 1

print(crash / ALL)