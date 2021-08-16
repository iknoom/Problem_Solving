from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    S = list(input().rstrip())


    if all(S[i] == '?' for i in range(n)):
        S[0] = 'R'

    for i in range(1, n):
        if S[i] == '?':
            if S[i - 1] == 'R':
                S[i] = 'B'
            elif S[i - 1] == 'B':
                S[i] = 'R'
    for i in range(n - 2, -1, -1):
        if S[i] == '?':
            if S[i + 1] == 'R':
                S[i] = 'B'
            elif S[i + 1] == 'B':
                S[i] = 'R'
    print(''.join(S))

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()