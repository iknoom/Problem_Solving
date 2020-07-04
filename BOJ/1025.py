square = set([i * i for i in range(100000)])
N, M = map(int, input().split())
board = [input() for _ in range(N)]
answer = -1

def solve(x0, y0):
    global answer
    for dx in range(-10, 10):
        for dy in range(-10, 10):
            if dx == 0 and dy == 0: continue
            tmp = []
            x, y = x0, y0
            while 0 <= x < M and 0 <= y < N:
                tmp.append(board[y][x])
                number = int(''.join(tmp))
                if number in square:
                    answer = max(answer, number)
                x += dx
                y += dy

if __name__ == '__main__':
    for x in range(M):
        for y in range(N):
            solve(x, y)
    print(answer)