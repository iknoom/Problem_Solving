from sys import stdin
input = stdin.readline

def solution():
    n = int(input())
    A = list(map(int, input().rstrip()))
    L = n // 2
    if 0 not in A:
        print(1, L, 2, L + 1)
        return
    for i in range(n):
        if i + L >= n:
            break
        if A[i] == 0:
            print(i + 1, i + L + 1, i + 2, i + L + 1)
            return
    for i in range(n - 1, -1, -1):
        if A[i] == 0:
            print(i - L + 1, i + 1, i - L + 1, i)
            return

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()