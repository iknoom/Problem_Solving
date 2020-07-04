dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def fill_queue(queue, vst):
    for i in range(M):
        if adj[0][i] == '0':
            vst[0][i] = True
            queue.append((i, 0))

def BFS(queue, vst):
    for x, y in queue:
        for i in range(4):
            X, Y = x + dx[i], y + dy[i]
            if 0 <= X < M and 0 <= Y < N and adj[Y][X] == '0' and not vst[Y][X]:
                vst[Y][X] = True
                queue.append((X, Y))

if __name__ == "__main__":
    N, M = map(int, input().split())
    adj = [input() for _ in range(N)]
    vst = [[False] * M for _ in range(N)]

    queue = []
    fill_queue(queue, vst)
    BFS(queue, vst)

    ans = False
    for i in range(M):
        if vst[-1][i]:
            ans = True

    print('YES' if ans else 'NO')