dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
INF = float('inf')
turn = [3, 2, 1, 0] # \
turn2 = [1, 0, 3, 2] # /

def is_ok(x, y):
    return 0 <= x < M and 0 <= y < N

def solution(x, y, i):
    vst = set()
    ret = 0
    vst.add((x, y, i))
    while True:
        x += dx[i]
        y += dy[i]
        ret += 1
        if not is_ok(x, y):
            return ret
        if (x, y, i) in vst:
            return INF
        if board[y][x] == 'C':
            return ret
        if board[y][x] == '/':
            i = turn2[i]
        if board[y][x] == '\\':
            i = turn[i]
        vst.add((x, y, i))

if __name__ == '__main__':
    N, M = map(int, input().split())
    board = [input() for _ in range(N)]
    sy, sx = map(int, input().split())
    answer = [solution(sx - 1, sy - 1, i) for i in range(4)]
    answerL = 'URDL'
    for i in range(4):
        if answer[i] == max(answer):
            print(answerL[i])
            if answer[i] == INF:
                print("Voyager")
            else:
                print(answer[i])
            break