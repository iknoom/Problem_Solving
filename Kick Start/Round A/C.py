import sys
import heapq
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def is_ok(N, M, x, y):
    return 0 <= x < M and 0 <= y < N

def solution(N, M, G):
    ret = 0
    queue = []
    for y in range(N):
        for x in range(M):
            queue.append((-G[y][x], x, y))
    heapq.heapify(queue)
    vst = [[False] * M for _ in range(N)]
    while queue:
        h, x, y = heapq.heappop(queue)
        if vst[y][x]: continue
        h = -h
        vst[y][x] = True
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            if not is_ok(N, M, x1, y1):
                continue
            if h - G[y1][x1] > 1:
                ret += h - G[y1][x1] - 1
                G[y1][x1] = h - 1
                heapq.heappush(queue, (-G[y1][x1], x1, y1))
    return ret

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        N, M = map(int, input().split())
        G = [list(map(int, input().split())) for _ in range(N)]
        answer = solution(N, M, G)
        print("Case #" + str(case) + ":", answer)