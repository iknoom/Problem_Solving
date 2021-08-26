from sys import stdin
input = stdin.readline

def solution():
    l, r = map(int, input().split())
    mid = r // 2 + 1
    if mid < l:
        print(r - l)
    else:
        print(r % mid)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()