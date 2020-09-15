import sys

input = sys.stdin.readline

def solution():
    x, y, k = map(int, input().split())
    y_n = k
    require_stick = (y * y_n) + (k - 1)
    x_n = require_stick // (x - 1)
    if require_stick % (x - 1):
        x_n += 1
    print(y_n + x_n)



if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()