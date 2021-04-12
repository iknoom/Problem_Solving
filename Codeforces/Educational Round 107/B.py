from sys import stdin
input = stdin.readline


def solution():
    a, b, c = map(int, input().split())
    g = 1
    while len(str(g)) < c:
        g *= 5
    x = y = g
    while len(str(x)) < a:
        x *= 2
    while len(str(y)) < b:
        y *= 3
    print(x, y)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()