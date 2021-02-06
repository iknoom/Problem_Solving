import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    X = sorted(map(int, input().split()), reverse=True)
    vst = set()
    for x in X:
        if x + 1 not in vst:
            vst.add(x + 1)
        else:
            vst.add(x)
    print(len(vst))


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()