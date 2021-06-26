M, N = map(int, input().split())
U, L, R, D = map(int, input().split())
arr = [['#'] * (N + L + R) for _ in range(M + U + D)]
for i in range(N + L + R):
    for j in range(M + U + D):
        if (i + j) % 2:
            arr[j][i] = '.'
puzzle = [input() for _ in range(M)]
for y in range(M):
    for x in range(N):
        arr[U + y][L + x] = puzzle[y][x]

for row in arr:
    print(''.join(row))