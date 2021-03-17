from sys import stdin
input = stdin.readline

def sub_solution(n):
    if n % 2:
        return [1, n//2, n//2]
    else:
        m = n // 2
        if m % 2:
            return [2, (n - 2) // 2, (n - 2) // 2]
        else:
            return [n // 4, n // 4, n // 2]

def solution():
    n, k = map(int, input().split())
    x = n - (k - 3)
    answer = sub_solution(x) + [1] * (k - 3)
    print(*answer)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()