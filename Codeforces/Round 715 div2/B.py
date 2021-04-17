from sys import stdin
input = stdin.readline


def solution():
    N = int(input())
    S = input().rstrip()
    Mcount = 0
    Tcount = 0
    for c in S:
        if c == 'M':
            Mcount += 1
        else:
            Tcount += 1
        if Tcount < Mcount:
            return False
    if Tcount != Mcount * 2:
        return False
    Mcount = 0
    Tcount = 0
    for c in S[::-1]:
        if c == 'M':
            Mcount += 1
        else:
            Tcount += 1
        if Tcount < Mcount:
            return False
    return True


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        if solution():
            print("YES")
        else:
            print("NO")