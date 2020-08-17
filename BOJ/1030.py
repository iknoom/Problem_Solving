def sol(s0, r0, c0, color):
    if s0 == 0:
        if R1 <= r0 <= R2 and C1 <= c0 <= C2:
            ans[r0 - R1][c0 - C1] = color
        return
    s1 = s0 - 1
    L = N ** s1
    for i in range(N):
        for j in range(N):
            r1 = r0 + L * i
            c1 = c0 + L * j
            if r1 + L < R1 or R2 < r1: continue
            if c1 + L < C1 or C2 < c1: continue
            sol(s1, r1, c1, colors[color][i][j])

if __name__ == "__main__":
    s, N, K, R1, R2, C1, C2 = map(int, input().split())
    colors = []
    colors.append([[0] * N for _ in range(N)])
    colors.append([[1] * N for _ in range(N)])
    for i in range((N - K) // 2, (N - K) // 2 + K):
        for j in range((N - K) // 2, (N - K) // 2 + K):
            colors[0][i][j] = 1

    ans = [[0] * (C2 - C1 + 1) for _ in range(R2 - R1 + 1)]

    sol(s, 0, 0, 0)

    for row in ans:
        print(''.join(map(str,row)))