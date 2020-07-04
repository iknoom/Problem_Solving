N, M = map(int, input().split())
A = [list(map(int, input())) for _ in range(N)]
B = [list(map(int, input())) for _ in range(N)]
ans = 0

def op(x, y):
    for i in range(3):
        for j in range(3):
            A[y + i][x + j] ^= 1

for x in range(M - 2):
    for y in range(N - 2):
        if A[y][x] != B[y][x]:
            ans += 1
            op(x, y)

print(ans if all(A[y][x] == B[y][x] for x in range(M) for y in range(N)) else -1)