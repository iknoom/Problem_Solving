import sys
from math import sqrt
input = sys.stdin.readline


def draw_circle_filled(R):
    ret = 0
    for x in range(-R, R + 1):
        for y in range(-R, R + 1):
            if (x * x + y * y) * 4 < R * R * 4 + 4 * R + 1:
                ret += 1
    return ret


def draw_circle_filled_wrong(R):
    vst = set()
    for r in range(0, R + 1):
        for x in range(-r, r + 1):
            y = round(sqrt(r * r - x * x))
            vst.add((x, y))
            vst.add((x, -y))
            vst.add((y, x))
            vst.add((-y, x))
    return len(vst)


def solution():
    R = int(input())
    correct = draw_circle_filled(R)
    wrong = draw_circle_filled_wrong(R)
    return correct - wrong


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())