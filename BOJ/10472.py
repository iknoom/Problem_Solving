dx = [1, -1, 0, 0, 0]
dy = [0, 0, 1, -1, 0]

T = int(input())
for _ in range(T):
    puzzle = []
    for _ in range(3):
        row = []
        for c in input():
            if c == '*': row.append(1)
            else: row.append(0)
        puzzle.append(row)
    answer = 9
    for i in range((1 << 9)):
        count = 0
        cur = [[0] * 3 for _ in range(3)]
        for x in range(3):
            for y in range(3):
                xy = x * 3 + y
                if i & (1 << xy) == 0:
                    continue
                count += 1
                for j in range(5):
                    x1, y1 = x + dx[j], y + dy[j]
                    if 0 <= x1 < 3 and 0 <= y1 < 3:
                        cur[y1][x1] ^= 1
        if str(cur) == str(puzzle):
            answer = min(answer, count)
    print(answer)