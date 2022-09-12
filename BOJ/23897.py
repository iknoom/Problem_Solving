from sys import stdin
input = stdin.readline


def solution(n, k, arr):
    l = 0
    r = 10 ** 9
    while l + 1 < r:
        mid = (l + r) // 2
        cur = 0
        for i in range(n - 1):
            cur += (arr[i + 1] - arr[i] - 1) // mid
        if cur > k:
            l = mid
        else:
            r = mid
    return r


if __name__ == "__main__":
    T = int(input())
    for testcase in range(1, T + 1):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        answer = solution(n, k, arr)
        print(f'Case #{testcase}:', answer)