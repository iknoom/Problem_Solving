dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def is_ok(x, y):
    return 0 <= x < M and 0 <= y < N


def bfs(x, y, color):
    queue = [(x, y)]
    sima[y][x] = color
    for x, y in queue:
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            if not is_ok(x1, y1):
                continue
            if sima[y1][x1] or not is_sima[y1][x1]:
                continue
            sima[y1][x1] = color
            queue.append((x1, y1))


def coloring_sima():
    global y, x
    count = 0
    for y in range(N):
        for x in range(M):
            if is_sima[y][x] and not sima[y][x]:
                count += 1
                bfs(x, y, count)
    return count


def get_hasi():
    ret = []
    for y in range(N):
        for x in range(M):
            if not is_sima[y][x]:
                continue
            for i in range(4):
                x1, y1 = x + dx[i], y + dy[i]
                if not is_ok(x1, y1) or is_sima[y1][x1]:
                    continue
                while is_ok(x1, y1) and not is_sima[y1][x1]:
                    x1 += dx[i]
                    y1 += dy[i]
                if not is_ok(x1, y1):
                    continue
                ret.append((sima[y][x], sima[y1][x1], abs(x1 - x) + abs(y1 - y) - 1))
    return ret


def find(v):
    if p[v] == v:
        return v
    p[v] = find(p[v])
    return p[v]


def union(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return False
    p[u] = v
    return True


if __name__ == '__main__':
    N, M = map(int, input().split())
    is_sima = [list(map(int, input().split())) for _ in range(N)]
    sima = [[0] * M for _ in range(N)]
    # coloring sima
    V = coloring_sima()
    # get hasi
    hasi = get_hasi()
    # get MST
    p = [i for i in range(V + 1)]
    hasi.sort(key=lambda x: x[2])
    answer = 0
    E = 0
    for u, v, w in hasi:
        if w < 2:
            continue
        if union(u, v):
            answer += w
            E += 1
    if E == V - 1:
        print(answer)
    else:
        print(-1)