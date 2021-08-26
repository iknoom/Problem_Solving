from sys import stdin
input = stdin.readline

def solution():
    n, q = map(int, input().split())
    S = input().rstrip()
    arr = [0] * (n + 1)
    sign = 1
    for i in range(1, n + 1):
        if S[i - 1] == '+':
            arr[i] = arr[i - 1] + 1 * sign
        else:
            arr[i] = arr[i - 1] - 1 * sign
        sign *= -1
    for _ in range(q):
        l, r = map(int, input().split())
        ans = arr[r] - arr[l - 1]
        if ans == 0:
            print(0)
        elif ans % 2 == 1:
            print(1)
        else:
            print(2)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()