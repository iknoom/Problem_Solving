from sys import setrecursionlimit
setrecursionlimit(10**9)

dxy = {'D': (0, 1), 'U': (0, -1), 'L': (-1, 0), 'R': (1, 0)}

def find(u):
    if p[u] != u: p[u] = find(p[u])
    return p[u]

if __name__ == "__main__":
    N, M = map(int, input().split())
    B = [input() for _ in range(N)]
    p = [i for i in range(N * M)]
    vst = [[False] * M for _ in range(N)]

    for j in range(N):
        for i in range(M):
            x, y = i, j
            while True:
                if vst[y][x]: break
                vst[y][x] = True
                x1 = x + dxy[B[y][x]][0]
                y1 = y + dxy[B[y][x]][1]
                if 0 <= x1 < M and 0 <= y1 < N:
                    p[find(x1 + y1 * M)] = p[find(x + y * M)]
                    x, y = x1, y1
                    continue
                break
    print(len(set(find(i) for i in range(N * M))))