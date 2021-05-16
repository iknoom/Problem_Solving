from sys import stdin
input = stdin.readline

def get_min(l, r):
    print('M', l + 1, r + 1, flush=True)
    i = int(input())
    return i - 1

def swap(a, b):
    print('S', a + 1, b + 1, flush=True)
    x = int(input())

def solution():
    for i in range(N - 1):
        min_idx = get_min(i, N - 1)
        if min_idx != i:
            swap(i, min_idx)
    print('D', flush=True)
    x = int(input())


if __name__ == '__main__':
    T, N = map(int, input().split())
    for case in range(1, T + 1):
        solution()