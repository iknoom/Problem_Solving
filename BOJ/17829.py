N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
while N > 1:
    A = [[sorted([A[r * 2][c * 2],
                  A[r * 2 + 1][c * 2],
                  A[r * 2][c * 2 + 1],
                  A[r * 2 + 1][c * 2 + 1]])[2] for c in range(N // 2)] for r in range(N // 2)]
    N //= 2
print(A[0][0])