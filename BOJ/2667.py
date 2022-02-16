from sys import stdin
input = stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(sx, sy, arr, visited):
    queue = [(sx, sy)]
    visited[sy][sx] = True
    count = 0
    for x, y in queue:
        count += 1
        for i in range(4):
            x2, y2 = x + dx[i], y + dy[i]
            if x2 < 0 or x2 >= N or y2 < 0 or y2 >= N:
                continue
            if visited[y2][x2] or arr[y2][x2] == 0:
                continue
            visited[y2][x2] = True
            queue.append((x2, y2))
    return count

N = int(input())
arr = [list(map(int, input().rstrip())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
answer = []

for y in range(N):
    for x in range(N):
        if arr[y][x] == 1 and not visited[y][x]:
            ret = bfs(x, y, arr, visited)
            answer.append(ret)

answer.sort()
print(len(answer))
for e in answer:
    print(e)