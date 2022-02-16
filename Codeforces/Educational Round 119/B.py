import sys

input = sys.stdin.readline


def solution():
    w, h = map(int, input().split())
    X1 = list(map(int, input().split()))[1:]
    X2 = list(map(int, input().split()))[1:]
    Y1 = list(map(int, input().split()))[1:]
    Y2 = list(map(int, input().split()))[1:]
    x = max(X1[-1] - X1[0], X2[-1] - X2[0])
    y = max(Y1[-1] - Y1[0], Y2[-1] - Y2[0])
    print(max(h * x, w * y))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()