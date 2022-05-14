import sys
input = sys.stdin.readline


def solution():
    N, K = map(int, input().split())
    if K % 2:
        print("IMPOSSIBLE")
        return
    arr = [] # (move, i, j)
    i = 1
    length = N - 1
    move = length * 4 - 2
    arr.append((move, i, i + move + 1))
    while True:
        i += length + 1
        length -= 1
        move -= 2
        if length <= 0:
            break
        arr.append((move, i, i + move + 1))
        move -= 2
        i += length + 1
        arr.append((move, i, i + move + 1))

    answer = []
    to_move = N * N - 1 - K
    i = 0
    while i < len(arr):
        move, *ab = arr[i]
        if move <= to_move:
            to_move -= move
            answer.append(ab)
            i += 3
        i += 1
    if to_move > 0:
        print("IMPOSSIBLE")
        return
    print(len(answer))
    for ab in answer:
        print(*ab)


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ": ", end='')
        solution()