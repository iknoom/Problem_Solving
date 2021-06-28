from sys import stdin
input = stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def is_key(c):
    return ord('a') <= ord(c) <= ord('z')

def is_door(c):
    return ord('A') <= ord(c) <= ord('Z')

def door_to_idx(c):
    return ord(c) - ord('A')

def key_to_idx(c):
    return ord(c) - ord('a')

def is_ok(x, y):
    return 0 <= x < w and 0 <= y < h

def solution():
    key_vst = [False] * 26
    door_stack = [[] for _ in range(26)]
    vst = [[False] * w for _ in range(h)]
    for key in keys:
        key_vst[key] = True

    tmp = []
    for i in range(h):
        if board[i][0] != '*':
            tmp.append((0, i))
        if board[i][w - 1] != '*':
            tmp.append((w - 1, i))
    for i in range(1, w - 1):
        if board[0][i] != '*':
            tmp.append((i, 0))
        if board[h - 1][i] != '*':
            tmp.append((i, h - 1))

    queue = []
    for x, y in tmp:
        if is_key(board[y][x]):
            key_vst[key_to_idx(board[y][x])] = True
            vst[y][x] = True
            queue.append((x, y))
        elif board[y][x] in '$.':
            vst[y][x] = True
            queue.append((x, y))

    for x, y in tmp:
        if is_door(board[y][x]):
            idx = door_to_idx(board[y][x])
            if key_vst[idx]:
                vst[y][x] = True
                queue.append((x, y))
            else:
                door_stack[idx].append((x, y))

    # bfs
    answer = 0
    for x, y in queue:
        if board[y][x] == '$':
            answer += 1
        for i in range(4):
            x1, y1 = x + dx[i], y + dy[i]
            if not is_ok(x1, y1):
                continue
            elif vst[y1][x1] or board[y1][x1] == '*':
                continue
            elif board[y1][x1] in '.$':
                vst[y1][x1] = True
                queue.append((x1, y1))
            # door
            elif is_door(board[y1][x1]):
                idx = door_to_idx(board[y1][x1])
                if key_vst[idx]:
                    vst[y1][x1] = True
                    queue.append((x1, y1))
                else:
                    door_stack[idx].append((x1, y1))
            # key
            elif is_key(board[y1][x1]):
                idx = key_to_idx(board[y1][x1])
                key_vst[idx] = True
                while door_stack[idx]:
                    x2, y2 = door_stack[idx].pop()
                    vst[y2][x2] = True
                    queue.append((x2, y2))
                vst[y1][x1] = True
                queue.append((x1, y1))
    return answer

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        h, w = map(int, input().split())
        board = [input().rstrip() for _ in range(h)]
        key_input = input().rstrip()
        if key_input == '0':
            keys = []
        else:
            keys = list(map(key_to_idx, key_input))
        answer = solution()
        print(answer)