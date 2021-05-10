import copy

IMPOSSIBLE = 100
BACK = [
    [(0, 0), (0, 1), (0, 2)],
    [(1, 0), (1, 1), (1, 2)],
    [(2, 0), (2, 1), (2, 2)],
    [(0, 0), (1, 0), (2, 0)],
    [(0, 1), (1, 1), (2, 1)],
    [(0, 2), (1, 2), (2, 2)],
    [(0, 0), (1, 1), (2, 2)],
    [(0, 2), (1, 1), (2, 0)]
]

def solution(board):
    answer = IMPOSSIBLE
    for i in range(1 << 8):
        count = 0
        C = copy.deepcopy(board)
        for j in range(8):
            if i & (1 << j):
                count += 1
                for x, y in BACK[j]:
                    C[y][x] = 'T' if C[y][x] == 'H' else 'H'
        S = set(C[y][x] for x in range(3) for y in range(3))
        if len(S) == 1:
            answer = min(answer, count)
    if answer == IMPOSSIBLE:
        return -1
    else:
        return answer

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        board = [input().split() for _ in range(3)]
        answer = solution(board)
        print(answer)