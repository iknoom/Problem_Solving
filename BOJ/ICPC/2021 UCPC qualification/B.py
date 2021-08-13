dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
B = [list(map(int, input().split())) for _ in range(N)]
check = [[0] * M for _ in range(N)]
arr = set()
sx = sy = -1
for i in range(N):
    for j in range(M):
        if A[i][j] != B[i][j]:
            check[i][j] = 1
            arr.add(B[i][j])
            sx = j
            sy = i

if sx < 0 and sy < 0:
    print("YES")

elif len(arr) > 1:
    print("NO")

else:
    check2 = [[0] * M for _ in range(N)]
    # bfs
    check2[sy][sx] = 1
    q = [(sx, sy)]
    for cx, cy in q:
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or nx >= M: continue
            if ny < 0 or ny >= N: continue
            if check2[ny][nx]: continue
            if A[cy][cx] != A[ny][nx]: continue
            check2[ny][nx] = 1
            q.append((nx, ny))
    if all(check[i][j] == check2[i][j] for i in range(N) for j in range(M)):
        print("YES")
    else:
        print("NO")
