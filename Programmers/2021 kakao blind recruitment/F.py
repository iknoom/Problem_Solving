from itertools import permutations
from copy import deepcopy

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
INF = float('inf')

def in_board(x, y):
    return (0 <= x < 4 and 0 <= y < 4)

def get_distance(A, _from, _to):
    x0, y0 = _from
    tx, ty = _to
    # BFS
    q = [(x0, y0, 0)]
    vst = [[False] * 4 for _ in range(4)]
    vst[y0][x0] = True
    for x, y, count in q:
        if x == tx and y == ty: return count
        # not Ctrl
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            if not in_board(x1, y1): continue
            if vst[y1][x1]: continue
            vst[y1][x1] = True
            q.append((x1, y1, count + 1))
        # Ctrl
        for i in range(4):
            x1, y1 = x, y
            while True:
                if not in_board(x1 + dx[i], y1 + dy[i]): break
                x1 += dx[i]
                y1 += dy[i]
                if A[y1][x1] > 0: break
            if vst[y1][x1]: continue
            vst[y1][x1] = True
            q.append((x1, y1, count + 1))

def find_card(A, card):
    ret = []
    for y in range(4):
        for x in range(4):
            if A[y][x] == card:
                ret.append((x, y))
    return ret

def sub_solution(A, r, c, P):
    queue = [(c, r, 0)]
    for card in P:
        to = find_card(A, card)
        total_dist = [INF, INF]
        for x, y, dist in queue:
            for i in range(2):
                ret = dist
                mx, my = to[1 - i]
                ret += get_distance(A, (x, y), (mx, my))
                ret += get_distance(A, (mx, my), to[i])
                total_dist[i] = min(total_dist[i], ret)
        queue = [(to[0][0], to[0][1], total_dist[0]), (to[1][0], to[1][1], total_dist[1])]
        for x, y in to:
            A[y][x] = 0
    return min(queue[0][2], queue[1][2])

def solution(board, r, c):
    cards = set()
    for row in board:
        cards |= set(row)
    cards -= {0}
    answer = min(sub_solution(deepcopy(board), r, c, P) for P in permutations(cards))
    answer += len(cards) * 2
    return answer

if __name__ == "__main__":
    print(solution([[1, 0, 0, 3], [2, 0, 0, 0], [0, 0, 0, 2], [3, 0, 1, 0]], 1, 0))