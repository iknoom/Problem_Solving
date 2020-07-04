from itertools import combinations as cb
B = [input() for _ in range(5)]

def is_seven(S):
    m = [(k//5, k%5) for k in S]
    if sum(B[y][x] == 'S' for x, y in m) < 4: return False
    ret = [True] + [False] * 6
    q = [m[0]]
    for x, y in q:
        for i in range(7):
            x0, y0 = m[i]
            if not ret[i] and abs(x0 - x) + abs(y0 - y) == 1:
                ret[i] = True
                q.append(m[i])
    return all(ret)

print(sum(is_seven(k) for k in cb(range(25), 7)))