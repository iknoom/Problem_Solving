from sys import stdin
input = stdin.readline


def solution():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    inc = []
    dec = []
    for i in range(N):
        while B[i] < A[i]:
            A[i] -= 1
            dec.append(i + 1)
        while B[i] > A[i]:
            A[i] += 1
            inc.append(i + 1)
    if len(inc) == len(dec):
        print(len(inc))
        for a, b in zip(inc, dec):
            print(b, a)
    else:
        print(-1)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()