from sys import stdin
input = stdin.readline


def is_sorted(a):
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return False
    return True

def solution():
    n = int(input())
    A = list(map(int, input().split()))
    for i in range(100000):
        if is_sorted(A):
            print(i)
            return
        for i in range(i % 2, n, 2):
            if i < n - 1 and A[i] > A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()