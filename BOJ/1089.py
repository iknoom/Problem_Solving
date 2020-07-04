N = int(input())
P = '''###...#.###.###.#.#.###.###.###.###.###
#.#...#...#...#.#.#.#...#.....#.#.#.#.#
#.#...#.###.###.###.###.###...#.###.###
#.#...#.#.....#...#...#.#.#...#.#.#...#
###...#.###.###...#.###.###...#.###.###'''.split()
E = [input() for _ in range(5)]

def solve(i, j):
    for x in range(3):
        for y in range(5):
            if P[y][j * 4 + x] == '.' and E[y][i * 4 + x] == '#':
                return False
    return True

ans = [[j for j in range(10) if solve(i, j)] for i in range(N)]
cnt = 1
S = 0
for i in range(N):
    if not ans[-i - 1]:
        S = -1
        cnt = 1
        break
    S = (10 ** i) * cnt * sum(ans[-i - 1]) + S * len(ans[-i - 1])
    cnt *= len(ans[-i - 1])
print(S / cnt)