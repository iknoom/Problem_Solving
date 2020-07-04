input = __import__('sys').stdin.readline

m = int(input())
D = 19
next = [[0] * D for _ in range(m + 1)]
for i,k in enumerate(map(int, input().split())):
    next[i + 1][0] = k

for j in range(1, D):
    for i in range(m):
        next[i + 1][j] = next[next[i + 1][j - 1]][j - 1]

for _ in range(int(input())):
    n, x = map(int, input().split())
    steps = 19
    while True:
        if n >= (1 << steps): n, x = n - (1 << steps), next[x][steps]
        if not steps: break
        steps -= 1
    print(x)
