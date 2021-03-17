from sys import stdin
input = stdin.readline

def solution():
    n, k = map(int, input().split())
    if n % 2:
        print(1, n//2, n//2)
    else:
        m = n // 2
        if m % 2:
            print(2, (n - 2) // 2, (n - 2) // 2)
        else:
            print(n // 4, n // 4, n // 2)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()