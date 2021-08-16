from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(1, n):
        a[0] &= a[i]
    print(a[0])

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()