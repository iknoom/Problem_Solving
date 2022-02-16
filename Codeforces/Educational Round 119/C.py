import sys

input = sys.stdin.readline


def solution():
    n, k, x = map(int, input().split())
    S = input().rstrip() # 'a' or '*'
    arr = []
    for c in S:
        if c == 'a':
            arr.append(-1)
        else:
            if arr and arr[-1] > 0:
                arr[-1] += k
            else:
                arr.append(k + 1)
    answer = []
    mal = 1
    for c in arr:
        if c < 0:
            continue
        mal *= c
    for c in arr:
        if c < 0:
            answer.append('a')
        else:
            mal //= c
            while x > mal:
                x -= mal
                answer.append('b')
    print(''.join(answer))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()