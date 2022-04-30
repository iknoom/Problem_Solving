import sys
input = sys.stdin.readline

def sub_solution(arr):
    A = sum(arr)
    B = sum(x * x for x in arr)
    upper = B - A * A
    lower = 2 * A
    if A == 0:
        if B == 0:
            return 1
        return "IMPOSSIBLE"
    if upper % lower:
        return "IMPOSSIBLE"
    answer = upper // lower
    return answer

def solution():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    first = sub_solution(arr)
    if first == "IMPOSSIBLE" and K > 1:
        x = 1 - sum(arr)
        arr.append(x)
        return f'{x} {sub_solution(arr)}'
    return first


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())