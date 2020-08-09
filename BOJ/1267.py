input()
T = list(map(int, input().split()))
Y = 10 * sum(1 + t // 30 for t in T)
M = 15 * sum(1 + t // 60 for t in T)

if Y < M:
    print('Y', Y)
elif Y > M:
    print('M', M)
else:
    print('Y', 'M', Y)