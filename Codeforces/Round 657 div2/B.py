import sys

input = sys.stdin.readline


def solution():
    l, r, m = map(int, input().split())
    lr_diff = r - l
    MAX_left = m - l + r
    b = l
    c = r
    for a in range(l, r + 1):
        R = MAX_left % a
        if R > lr_diff * 2:
            continue
        else:
            b += min(lr_diff, R)
            R -= min(lr_diff, R)
            c -= min(lr_diff, R)

            print(a, b, c)
            break









if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()