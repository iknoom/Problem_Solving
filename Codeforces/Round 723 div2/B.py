from sys import stdin
input = stdin.readline


def solution():
    x = int(input())
    for i in range(12):
        a = 111 * i
        if x >= a and (x - a) % 11 == 0:
            return "YES"
    return "NO"


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        answer = solution()
        print(answer)