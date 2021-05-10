from sys import stdin
input = stdin.readline

def solution(N):
    if N == 0:
        print('-', end='')
        return
    solution(N - 1)
    print(' ' * (3**(N - 1)), end='')
    solution(N - 1)

while True:
    try:
        N = int(input())
        solution(N)
        print()
    except:
        break