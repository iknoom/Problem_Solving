dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

N = int(input())
FIND = int(input())
B = [[0] * N for _ in range(N)]

x = y = N // 2
cnt = 1
t = 0

while True:
    if 0 <= x < N and 0 <= y < N:
        B[y][x] = cnt
        cnt += 1
        x += dx[t]
        y += dy[t]
        if B[y + dy[(t+1)%4]][x + dx[(t+1)%4]] == 0:
            t =(t+1)%4
    else:
        break
for b in B: print(*b)
for i in range(N):
    for j in range(N):
        if B[i][j] == FIND:
            print(i + 1, j + 1)